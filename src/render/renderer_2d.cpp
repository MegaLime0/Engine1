#include "engine/asset_container.hpp"
#include "engine/render/shader.hpp"
#include <cstddef>
#include <engine/render/renderer_2d.hpp>
#include <engine/render/vertex.hpp>
#include <glad/glad.h>

namespace Engine {
namespace Render {


void Renderer2D::init(AssetManager& assetManager) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteVertex) * MaxQuadsPerBatch * 2, NULL, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices, GL_STATIC_DRAW);

    this->assets = &assetManager;
    AssetHandler<Shader> defaultShaderHandle = assets->shaders.load(
            "defaultShader", 
            Shader("res/shaders/default.vert", "res/shaders/default.frag")
            );
    defaultShader = assets->shaders.get(defaultShaderHandle);
}

void Renderer2D::begin(const Camera2D& camera) {
    cachedCamera = camera;
    verticeAmount = 0;
    currentTexture = {};
}

void Renderer2D::drawQuad(
        glm::vec2 pos, 
        glm::vec2 size, 
        AssetHandler<Texture2D>& newTexture,
        Shader* customShader,
        glm::vec4 color) 
{

    Shader* shaderToUse = customShader ? customShader : defaultShader;

    bool overVertexLimit = verticeAmount >= MaxVerticesPerBatch;
    bool textureChanged = currentTexture.isValid() && currentTexture.id != newTexture.id;
    bool shaderChanged = customShader != nullptr && customShader != shaderToUse;

    if (overVertexLimit || textureChanged || shaderChanged) {
        flush();
    }

    currentShader = shaderToUse;
    currentTexture = newTexture;

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

    currentShader->use();
}

} // namespace renderer
} // namespace engine
