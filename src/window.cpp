#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <engine/window.hpp>
#include <stdexcept>

namespace engine {

Window::Window(WindowConfig config) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error("Couldn't initialize video");
    }

    if (!SDL_Init(SDL_INIT_EVENTS)) {
        throw std::runtime_error("Couldn't initialize events");
    }

    _window = SDL_CreateWindow(
            config.title.c_str(), 
            config.width, 
            config.height,
            config.flags
            );

    if (!_window) {
        throw std::runtime_error("Couldn't create window");
    }

    _glContext = SDL_GL_CreateContext(_window);

    if (!_glContext) {
        throw std::runtime_error("Couldn't create GL context");
    }
}

Window::Window(int width, int height, std::string title, SDL_WindowFlags flags) {
    Window(WindowConfig {width, height, title, flags});
}

Window::~Window() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Window::makeFullscreen() {
    SDL_SetWindowFullscreen(_window, true);
}

void Window::makeWindowed() {
    SDL_SetWindowFullscreen(_window, false);
}

void Window::updateWindowFlags() {
    _wConf.flags = SDL_GetWindowFlags(_window);
}




} // namespace engine
