#pragma once

#include "engine/asset_manager.hpp"
#include "engine/configs.hpp"
#include "engine/render/camera_2d.hpp"
#include <engine/window.hpp>
#include <engine/render/renderer_2d.hpp>
#include <glm/ext/vector_float2.hpp>

// Main entrypoint to engine

namespace Engine {

class Engine {
    public:
        Engine(Config::Window wConf, Config::Render rConf, Config::Camera2D cConf);
        ~Engine();
        Render::Renderer2D* renderer = nullptr;

        void update();
    private:
        Window window;
        Render::Camera2D camera;
        AssetManager assets;

        Event _current;
};

}
