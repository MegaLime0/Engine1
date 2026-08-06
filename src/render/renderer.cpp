#include <engine/render/renderer.hpp>
#include <iostream>

namespace Engine {
namespace Render {

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
