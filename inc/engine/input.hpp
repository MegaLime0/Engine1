#pragma once
#include "engine/window.hpp"
#include <SDL3/SDL_events.h>

namespace engine {

// Handles input/events or smething
using Event = SDL_Event;

class Input {
    public:
        Input(Window &window);
        ~Input();

        void pollEvents(Event &event);
    private:
        // Input Key Buffer
};

}
