#include "engine/input/input_enums.hpp"
#include <algorithm>
#include <engine/input/input.hpp>
#include <utility>
#include <vector>

namespace engine {
namespace input {

// TODO: implement input constructor
Input::Input() {
}

// TODO: implement input desctructor
Input::~Input() {
}

void Input::bindAction(Action action, KeyCodes keycode) {
    // TODO: add option to include deadzone
    KeyActionMap.emplace(keycode, std::vector<Action>({action}));
    ActionMap.emplace(action, std::vector<Callback>());
    ActionFrame.emplace(action, 0);
}

void Input::bindActionCallback(Action action, Callback callback) {
    ActionMap.at(action).push_back(callback);
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

// TODO: implement input deadzone
bool Input::isActionPressed(Action action) {
    return ActionFrame.at(action) == 0.0 ? false : true;
    // return ActionFrame.at(action) == DEADZONE_FOR_THIS_ACTION ? false : true;
}


// TODO: implement rest of input functions


} // namespace input
} // namespace engine
