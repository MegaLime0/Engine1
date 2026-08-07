#pragma once

#include <SDL3/SDL.h>
#include <string>

namespace Engine {
namespace Config {

struct Window {
    int width = 1280;
    int height = 720;
    std::string title = "Generic Window Title";
    bool fullscreen = true;
    bool vsync = true;
};

struct Render {
    std::string defaultVShaderPath = "res/shaders/default.vert";
    std::string defaultFShaderPath = "res/shaders/default.frag";
};

struct Camera2D {
    float visibleWidth = 100.0f;
    float defaultZoom = 1.0f;
};

} // namespace Config
} // namespace Engine
