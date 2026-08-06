#pragma once

#include "engine/input/input_state.hpp"
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_scancode.h>
#include <engine/math/vector2d.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>
#include <string>
#include <vector>

namespace Engine {
namespace Input {

// Handles input/events or smething
// Should use buffering
using Event = SDL_Event;
using Action = std::string;
using Callback = void (*)(float);
using Deadzone = float;

struct ActionInfo {
    Deadzone deadzone;
    std::vector<Callback> callbacks;
};

// TODO: implement input deadzone

// TODO: properly implement input class
class Input {
    public:
        Input();
        ~Input();

        void processKeyboard(Event &event);

        void processMouseButton(Event &event);
        void processMouseWheel(Event &event);
        void processMouseMotion(Event &event);

        void processGamepadButton(Event &event);
        void processGamepadAxis(Event &event);

        bool isActionPressed(Action action);
        float getActionValue(Action action);

    private:
};

} // namespace input
} // namespace engine
