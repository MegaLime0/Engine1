#include <engine/render/base_render_object.hpp>
#include "engine/render/shader.hpp"

namespace engine {
namespace render {

BaseRenderObject::BaseRenderObject(Shader shader, std::vector<std::unique_ptr<BaseTexture>> textures, RenderData data)
    :   shader(shader), 
        textures(textures),
        data(data)
{
}

} // namespace render
} // namespace engine
