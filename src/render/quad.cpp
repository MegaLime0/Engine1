#include "engine/render/base_render_object.hpp"
#include <engine/render/quad.hpp>
#include <engine/render/render_data.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture_2d.hpp>
#include <vector>

namespace engine {
namespace render {

Quad::Quad(Shader shader, Texture2D texture, RenderData data)
    : BaseRenderObject(shader, {texture}, data) {
        // TODO: implement
        // move data to gpu
        // vao/ebo/tex
}

} // namespace render
} // namespace engine
