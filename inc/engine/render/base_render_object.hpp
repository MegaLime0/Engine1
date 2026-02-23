#pragma once

#include <engine/render/shader.hpp>
#include <engine/render/base_texture.hpp>
#include <glad/glad.h>

namespace engine {
namespace render {

class BaseRenderObject {
    public:
        // bind self VAO, Texture and Shader
        virtual void bind();
    protected:
        Shader shader;
        GLuint VAO, VBO;
};


} // namespace render
} // namespace engine
