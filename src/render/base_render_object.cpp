#include "engine/render/shader.hpp"
#include <engine/render/base_render_object.hpp>

namespace engine {
namespace render {

BaseRenderObject::BaseRenderObject(Shader shader,
                                   std::vector<BaseTexture> textures,
                                   GLuint VAO, RenderData data)
    : shader(shader), textures(textures) 
{
    this->VAO = VAO;
    this->data = data;
}

} // namespace render
} // namespace engine
