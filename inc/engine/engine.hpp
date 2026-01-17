#pragma once
#include <engine/window.hpp>
#include <engine/input.hpp>
#include <engine/renderer.hpp>

// Main entrypoint to engine

namespace engine {

class Engine {
    public:
    private:
        Window window;
        Renderer renderer;
        Input input;
};

}
