#pragma once

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>
#include <engine/math/vector2d.hpp>
#include <engine/input/input_enums.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>
#include <map>

namespace engine {
namespace input {

// Handles input/events or smething
// Should use buffering
using Event = SDL_Event;

// TODO: properly implement input class
class Input {
    public:
        Input(Window &window);
        ~Input();

        void processKeyboard(Event &event);

        void processMouseButton(Event &event);
        void processMouseWheel(Event &event);
        void processMouseMotion(Event &event);

        void processGamepadButton(Event &event);
        void processGamepadAxis(Event &event);

    private:
        math::Vector2D _mousePos;
        std::map<SDL_Scancode, const char*> _keyMap;
        // TODO: make action datatype
        std::map<const char*, const char*> _actionMap;
        // Input Buffer

        // Merge inputs together into one "block"
};

} // input
} // namespace engine
