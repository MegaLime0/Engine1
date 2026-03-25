#include <engine/render/base_render_object.hpp>
#include <engine/render/base_texture.hpp>
#include <engine/render/quad.hpp>
#include <engine/render/render_data.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture_2d.hpp>
#include <glad/glad.h>
#include <vector>

namespace engine {
namespace render {

Quad::Quad(Shader shader, Texture2D texture, RenderData data)
    : BaseRenderObject(shader, {texture}, data) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(float),
                 data.vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.indices.size() * sizeof(int),
                 data.indices.data(), GL_STATIC_DRAW);
}

Quad::Quad(Shader shader, Texture2D texture, RenderData data, GLenum draw)
    : BaseRenderObject(shader, {texture}, data) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(float),
                 data.vertices.data(), draw);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.indices.size() * sizeof(int),
                 data.indices.data(), draw);
}

void Quad::bind() {
    glBindVertexArray(VAO);
    textures[0].bind();
}

void Quad::render() {
    bind();

    glDrawElements(GL_TRIANGLES, data.indices.size(), GL_UNSIGNED_INT,(void*)0);
}

} // namespace render
} // namespace engine
