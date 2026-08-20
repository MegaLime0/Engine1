#include "engine/asset_container.hpp"
#include "engine/configs.hpp"
#include "engine/render/shader.hpp"
#include "engine/render/texture_2d.hpp"
#include <cstddef>
#include <engine/render/renderer_2d.hpp>
#include <engine/render/vertex.hpp>
#include <glad/glad.h>

namespace Engine {
namespace Render {


void Renderer2D::init(Config::Render config, AssetManager& assetManager) {
    this->assets = &assetManager;
    AssetHandler<Shader> defaultShaderHandle = assets->shaders.load(
            "defaultShader", 
            Shader(config.defaultVShaderPath, config.defaultFShaderPath)
            );
    defaultShader = assets->shaders.get(defaultShaderHandle);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteVertex) * MaxQuadsPerBatch * 2, NULL, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, false, offsetof(SpriteVertex, pos), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, 2, GL_FLOAT, false, offsetof(SpriteVertex, uv), nullptr);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 4, GL_FLOAT, false, offsetof(SpriteVertex, color), nullptr);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    // Generate indice array
    constexpr size_t indiceAmount = MaxQuadsPerBatch * 6;
    std::array<uint32_t, indiceAmount> quadIndices;

    for (int i = 0; i < MaxQuadsPerBatch; i++) {
        // indexes go up by 6 per quad
        size_t idx = i * 6;
        // indice base values go up by 4 per quad (4 vertices in quad)
        uint32_t indc = i * 4;
        quadIndices[idx] = indc;
        quadIndices[idx + 1] = indc + 1;
        quadIndices[idx + 2] = indc + 2;
        quadIndices[idx + 3] = indc + 2;
        quadIndices[idx + 4] = indc + 3;
        quadIndices[idx + 5] = indc;
    }

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices.data(), GL_STATIC_DRAW);
}

void Renderer2D::begin(Camera2D& camera) {
    cachedCamera = &camera;
    verticeAmount = 0;
    // currentTexture = {};
    currentMaterial = {};
}

void Renderer2D::drawQuad(
        glm::vec2 pos, 
        glm::vec2 size, 
        Material material,
        glm::vec4 color) 
{
    bool overVertexLimit = verticeAmount >= MaxVerticesPerBatch;
    bool diffuseMapChanged = material.diffuseMap.isValid() && material.diffuseMap.id != currentMaterial.diffuseMap.id;
    bool normalMapChanged = material.normalMap.isValid() && material.normalMap.id != currentMaterial.normalMap.id;
    bool shaderChanged = material.shader != nullptr && material.shader != currentMaterial.shader;

    if (overVertexLimit || diffuseMapChanged || normalMapChanged || shaderChanged) {
        flush();
    }

    currentMaterial = material;

    spriteVertices[verticeAmount++] = { pos,                                {0, 0}, color };
    spriteVertices[verticeAmount++] = { {pos.x + size.x, pos.y},            {1, 0}, color };
    spriteVertices[verticeAmount++] = { {pos.x + size.x, pos.y + size.y},   {1, 1}, color };
    spriteVertices[verticeAmount++] = { {pos.x, pos.y + size.y},            {0, 1}, color };
}

void Renderer2D::end() {
    flush();
}

void Renderer2D::flush() {
    if (verticeAmount == 0) { return; }

    Shader* currentShader = currentMaterial.shader;

    currentShader->use();
    currentShader->setMatrix4("uViewProjection", cachedCamera->getViewProjection());
    // setting the index for sampler2d so they know which bound texture to use
    currentShader->setInt("uDiffuseMap", 0);
    currentShader->setInt("uNormalMap", 1);
    currentShader->setBool("uHasNormalMap", currentMaterial.normalMap.isValid());

    Texture2D* diffuseMap = assets->texture2ds.get(currentMaterial.diffuseMap);
    Texture2D* normalMap = assets->texture2ds.get(currentMaterial.normalMap);

    glActiveTexture(GL_TEXTURE0);
    diffuseMap->bind();
    glActiveTexture(GL_TEXTURE1);
    normalMap->bind();

    glBindVertexArray(vao);
    // we need to rebind ARRAY_BUFFER <-> vbo so that we can upload the data using BufferSubData
    // vao only remember vertexAttribPointers and which vbo they use, if we didn't have to upload data
    // only vao would need to be bound
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, verticeAmount * sizeof(SpriteVertex), spriteVertices.data());

    size_t quadCount = (verticeAmount / 4);
    size_t indiceAmount = quadCount * 6;
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indiceAmount), GL_UNSIGNED_INT, nullptr);
}

} // namespace Renderer
} // namespace Engine
