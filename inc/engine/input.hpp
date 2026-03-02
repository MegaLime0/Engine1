#pragma once
#include "engine/window.hpp"
#include <SDL3/SDL_events.h>

namespace engine {

// Handles input/events or smething
// Should use buffering
using Event = SDL_Event;

struct Actions {
    // KeysPressed
};

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
        // store MousePos
        // Input Buffer

        // Merge inputs together into one "block"
};

} // namespace engine
