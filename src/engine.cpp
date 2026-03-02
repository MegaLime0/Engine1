#include "engine/input.hpp"
#include "engine/window.hpp"
#include <engine/engine.hpp>

namespace engine {

Engine::Engine()
    :   window(400, 800, "Test", SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE),
        input(window) 
{

}

void Engine::update() {
    while (window.pollEvents(_current)) {
        switch (_current.type) {
            // Window events
            case SDL_EventType::SDL_EVENT_WINDOW_RESIZED:
                // TODO: Update renderer on resize
                break;
            case SDL_EventType::SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
                // TODO: Update renderer on fullscreen
                break;
            case SDL_EventType::SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
                //TODO: Update renderer on exit fullscreen
                break;
            // Input events
            case SDL_EventType::SDL_EVENT_KEY_DOWN:
                input.processKeyboard(_current);
                break;
            case SDL_EventType::SDL_EVENT_MOUSE_BUTTON_DOWN:
                input.processMouseButton(_current);
                break;
            case SDL_EventType::SDL_EVENT_MOUSE_WHEEL:
                input.processMouseWheel(_current);
                break;
            case SDL_EventType::SDL_EVENT_MOUSE_MOTION:
                input.processMouseMotion(_current);
                break;
            case SDL_EventType::SDL_EVENT_GAMEPAD_BUTTON_DOWN:
                input.processGamepadButton(_current);
                break;
            case SDL_EventType::SDL_EVENT_GAMEPAD_AXIS_MOTION:
                input.processGamepadAxis(_current);
                break;
            default:
                break;
        }
    }
}

} // namespace engine 
