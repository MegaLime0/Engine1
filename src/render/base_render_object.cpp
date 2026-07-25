#include <engine/render/base_render_object.hpp>
#include "engine/render/shader.hpp"

namespace engine {
namespace render {

BaseRenderObject::BaseRenderObject(Shader shader, std::vector<std::unique_ptr<BaseTexture>> textures, RenderData data)
    :   shader(shader), 
        textures(std::move(textures)),
        data(data)
{
}

BaseRenderObject::BaseRenderObject(Shader shader, std::unique_ptr<BaseTexture> texture, RenderData data)
    :   shader(shader), 
        data(data)
{
    textures.push_back(std::move(texture));
}

} // namespace render
} // namespace engine
