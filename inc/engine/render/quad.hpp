#pragma once

#include <engine/render/base_texture.hpp>
#include <engine/render/texture_2d.hpp>
#include <engine/render/base_render_object.hpp>

namespace engine {
namespace render {

class Quad : BaseRenderObject {
    public:
        Quad(Shader shader, Texture2D texture, RenderData data);
        void bind();
        void render();

    private:
        GLuint VAO, EBO;
};


} // namespace render
} // namespace engine
