#pragma once
#include <SDL3/SDL_events.h>

namespace engine {

// Handles input/events or smething
using Event = SDL_Event;

class Input {
    public:
        void pollEvents();
    private:
        // Input Key Buffer
};

}
