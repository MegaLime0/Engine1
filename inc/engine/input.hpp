#pragma once

#include <engine/math/vector2d.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>

namespace engine {

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
        // Input Buffer

        // Merge inputs together into one "block"
};

} // namespace engine
