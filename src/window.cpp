#include "engine/configs.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <glad/glad.h>
#include <engine/window.hpp>
#include <iostream>
#include <stdexcept>

namespace Engine {

Window::Window(Config::Window config) {
    std::cout << "Window Constructor Start" << std::endl;

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
            (config.fullscreen ? SDL_WINDOW_FULLSCREEN : 0) | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
            );

    if (!_window) {
        throw std::runtime_error("Couldn't create window");
    }

    _glContext = SDL_GL_CreateContext(_window);

    SDL_GL_SetSwapInterval(config.vsync ? 1 : 0);

    if (!_glContext) {
        throw std::runtime_error("Couldn't create GL context");
    }

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Couldn't get GL proc address");
    }

    std::cout << "Window Constructor End" << std::endl;
}

Window::Window(int width, int height, std::string title, bool fullscreen, bool vsync) {
    Window(Config::Window {width, height, title, fullscreen, vsync});
}

Window::~Window() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Window::makeFullscreen() {
    SDL_SetWindowFullscreen(_window, true);
    SDL_SyncWindow(_window);
}

void Window::makeWindowed() {
    SDL_SetWindowFullscreen(_window, false);
    SDL_SyncWindow(_window);
}

void Window::updateWindowFlags() {
    SDL_WindowFlags flags = SDL_GetWindowFlags(_window);
    _wConf.fullscreen = flags & SDL_WINDOW_FULLSCREEN;
    int interval;
    SDL_GL_GetSwapInterval(&interval);
    _wConf.vsync = abs(interval);
}

bool Window::pollEvents(Event &event) {
    return SDL_PollEvent(&event);
}

} // namespace Engine
