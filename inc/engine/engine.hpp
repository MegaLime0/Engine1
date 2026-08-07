#pragma once

#include "engine/asset_manager.hpp"
#include <engine/window.hpp>
#include <engine/render/renderer_2d.hpp>

// Main entrypoint to engine

namespace Engine {

class Engine {
    public:
        Engine();

        void update();
    private:
        Window window;
        Render::Renderer2D* renderer;
        AssetManager assets;

        Event _current;
};

}
