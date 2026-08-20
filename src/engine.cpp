#include "engine/configs.hpp"
#include "engine/render/camera_2d.hpp"
#include "engine/render/renderer_2d.hpp"
#include "engine/render/texture_2d.hpp"
#include "engine/window.hpp"
#include <engine/engine.hpp>
#include <iostream>

namespace Engine {

Engine::Engine(Config::Window wConf, Config::Render rConf, Config::Camera2D cConf)
    :   window(wConf), 
        camera(cConf , {wConf.width, wConf.height})
{
    renderer = new Render::Renderer2D();
    renderer->init(rConf, assets);
    std::cout << "Engine Constructor End" << std::endl;
}

void Engine::update() {
    std::cout << "In Update" << std::endl;
    while (window.pollEvents(_current)) {
        switch (_current.type) {
            // Window events
            case SDL_EventType::SDL_EVENT_WINDOW_RESIZED:
            case SDL_EventType::SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
            case SDL_EventType::SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
                glViewport(0, 0, _current.window.data1, _current.window.data2);
                break;
            // Input events
            // case SDL_EventType::SDL_EVENT_KEY_DOWN:
            //     input.processKeyboard(_current);
            //     break;
            // case SDL_EventType::SDL_EVENT_MOUSE_BUTTON_DOWN:
            //     input.processMouseButton(_current);
            //     break;
            // case SDL_EventType::SDL_EVENT_MOUSE_WHEEL:
            //     input.processMouseWheel(_current);
            //     break;
            // case SDL_EventType::SDL_EVENT_MOUSE_MOTION:
            //     input.processMouseMotion(_current);
            //     break;
            // case SDL_EventType::SDL_EVENT_GAMEPAD_BUTTON_DOWN:
            //     input.processGamepadButton(_current);
            //     break;
            // case SDL_EventType::SDL_EVENT_GAMEPAD_AXIS_MOTION:
            //     input.processGamepadAxis(_current);
            //     break;
            default:
                break;
        }
    }
}

Engine::~Engine() {
    delete renderer;
}

} // namespace engine 
