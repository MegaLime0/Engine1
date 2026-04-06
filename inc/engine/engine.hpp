#pragma once
#include "engine/asset_manager.hpp"
#include <engine/window.hpp>
#include <engine/input.hpp>
#include <engine/render/renderer.hpp>

// Main entrypoint to engine

namespace engine {

class Engine {
    public:
        Engine();

        void update();
    private:
        Window window;
        render::Renderer renderer;
        input::Input input;
        AssetManager assets;

        Event _current;
};

}
