#pragma once
#include <engine/window.hpp>
#include <engine/input.hpp>
#include <engine/renderer.hpp>

// Main entrypoint to engine

namespace engine {

class Engine {
    public:
        Engine();

        void update();
    private:
        Window window;
        Renderer renderer;
        Input input;

        Event _current;
};

}
