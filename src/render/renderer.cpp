#pragma once

#include "engine/render/base_texture.hpp"
#include <engine/render/renderer.hpp>

namespace engine {
namespace render {

// TODO: Construct renderer
Renderer::Renderer(int width, int height) {
    resizeViewport(width, height);
}

void Renderer::resizeViewport(int width, int height) {
    glViewport(0, 0, width, height);
}



} // namespace renderer
} // namespace engine
