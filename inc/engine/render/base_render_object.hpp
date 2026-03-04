#pragma once

#include <engine/render/render_data.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/base_texture.hpp>
#include <glad/glad.h>

namespace engine {
namespace render {

class BaseRenderObject {
    public:
        BaseRenderObject(Shader shader, std::vector<BaseTexture> textures, GLuint VAO, RenderData data);
        // bind self VAO, Texture and Shader
        virtual void bind();
        // render self. automatically calls bind
        virtual void render();

    protected:
        Shader shader;
        std::vector<BaseTexture> textures;
        GLuint VAO;
        RenderData data;
};


} // namespace render
} // namespace engine
