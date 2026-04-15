#include "engine/input/input_enums.hpp"
#include <SDL3/SDL_gamepad.h>
#include <algorithm>
#include <engine/input/input.hpp>
#include <vector>

namespace engine {
namespace input {

// TODO: implement input constructor
Input::Input() {
}

// TODO: implement input desctructor
Input::~Input() {
}

void Input::bindAction(Action action, KeyCodes keycode, Deadzone deadzone) {
    ActionInfo info = { deadzone,
        std::vector<Callback>(),
    };

    KeyActionMap.emplace(keycode, std::vector<Action>({action}));
    ActionMap.emplace(action, info);
    ActionFrame.emplace(action, 0);
}

void Input::bindActionCallback(Action action, Callback callback) {
    ActionMap.at(action).callbacks.push_back(callback);
}

void Input::unbindAction(Action action, KeyCodes keycode) {
    std::vector<Action> actions = KeyActionMap.at(keycode);

    for (int i = 0; i < actions.size(); i++) {
        Action target = actions.at(i);
        bool isEqual = std::lexicographical_compare(
                action.front(), action.back(), target.front(), target.back());
        if (isEqual) {
            // swap back and pop
            Action first = actions.at(i);
            actions[i] = actions.back();
            actions.back() = first;
            actions.pop_back();

            break;
        }
    }

    KeyActionMap.erase(keycode);
}

bool Input::isActionPressed(Action action) {
    return ActionFrame.at(action) ? true : false;
}

float Input::getActionValue(Action action) {
    Deadzone deadzone = ActionMap.at(action).deadzone;
    float actionValue = ActionFrame.at(action);

    return actionValue > deadzone ? actionValue : 0.0f ;
}

void Input::processKeyboard(Event &event) {
    KeyCodes code;
    switch (event.key.scancode) {
        case SDL_SCANCODE_0:
            code = KeyCodes::KB_0;
            break;
        case SDL_SCANCODE_1:
            code = KeyCodes::KB_1;
            break;
        case SDL_SCANCODE_2:
            code = KeyCodes::KB_2;
            break;
        case SDL_SCANCODE_3:
            code = KeyCodes::KB_3;
            break;
        case SDL_SCANCODE_4:
            code = KeyCodes::KB_4;
            break;
        case SDL_SCANCODE_5:
            code = KeyCodes::KB_5;
            break;
        case SDL_SCANCODE_6:
            code = KeyCodes::KB_6;
            break;
        case SDL_SCANCODE_7:
            code = KeyCodes::KB_7;
            break;
        case SDL_SCANCODE_8:
            code = KeyCodes::KB_8;
            break;
        case SDL_SCANCODE_9:
            code = KeyCodes::KB_9;
            break;
        case SDL_SCANCODE_Q:
            code = KeyCodes::KB_Q;
            break;
        case SDL_SCANCODE_W:
            code = KeyCodes::KB_W;
            break;
        case SDL_SCANCODE_E:
            code = KeyCodes::KB_E;
            break;
        case SDL_SCANCODE_R:
            code = KeyCodes::KB_R;
            break;
        case SDL_SCANCODE_T:
            code = KeyCodes::KB_T;
            break;
        case SDL_SCANCODE_Y:
            code = KeyCodes::KB_Y;
            break;
        case SDL_SCANCODE_U:
            code = KeyCodes::KB_U;
            break;
        // TODO: finish translating sdl event into KeyCodes

        case SDL_SCANCODE_UNKNOWN:
            code = KeyCodes::_INVALID;
            break;
        default:
            break;
    }
}
 

// TODO: implement rest of input functions


} // namespace input
} // namespace engine
