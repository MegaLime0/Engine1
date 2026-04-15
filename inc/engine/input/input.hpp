#pragma once

#include "engine/input/input_enums.hpp"
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_scancode.h>
#include <engine/math/vector2d.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace engine {
namespace input {

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

        void bindAction(Action action, KeyCodes keycode, Deadzone deadzone = 0.1f);
        void bindActionCallback(Action action, Callback callback);
        void unbindAction(Action action, KeyCodes keycode);

        bool isActionPressed(Action action);
        float getActionValue(Action action);

    private:
        // Input accumulated here each frame
        std::unordered_map<Action, float> ActionFrame;
        // Keycode to action
        std::unordered_map<KeyCodes, std::vector<Action>> KeyActionMap;
        // Action to callbacks and deadzone
        std::unordered_map<Action, ActionInfo> ActionMap;
};

} // namespace input
} // namespace engine
