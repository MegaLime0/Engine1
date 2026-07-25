#include "engine/render/base_texture.hpp"
#include <engine/render/renderer.hpp>
#include <iostream>

namespace engine {
namespace render {

// TODO: Construct renderer
Renderer::Renderer(int width, int height) {
    std::cout << "Renderer Constructor Start" << std::endl;
    resizeViewport(width, height);
    std::cout << "Renderer Constructor End" << std::endl;
}

void Renderer::resizeViewport(int width, int height) {
    glViewport(0, 0, width, height);
}



} // namespace renderer
} // namespace engine
