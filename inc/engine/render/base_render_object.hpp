#pragma once

#include <engine/render/render_data.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/base_texture.hpp>
#include <glad/glad.h>
#include <memory>

namespace engine {
namespace render {

class BaseRenderObject {
    public:
        BaseRenderObject(Shader shader, std::vector<std::unique_ptr<BaseTexture>> textures, RenderData data);
        BaseRenderObject(Shader shader, std::unique_ptr<BaseTexture> texture, RenderData data);
        virtual ~BaseRenderObject() {}
        // bind self VAO, Texture and Shader
        virtual void bind() = 0;
        // render self. automatically calls bind
        virtual void render() = 0;


    protected:
        Shader shader;
        std::vector<std::unique_ptr<BaseTexture>> textures;
        RenderData data;
};


} // namespace render
} // namespace engine
