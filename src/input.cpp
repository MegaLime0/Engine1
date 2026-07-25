#include <engine/input/input.hpp>

namespace engine {
namespace input {

Input::Input() {}
Input::~Input() {}

void Input::processKeyboard(Event &event) {
    return;
}

void Input::processMouseButton(Event &event) {}
void Input::processMouseWheel(Event &event) {}
void Input::processMouseMotion(Event &event) {}
void Input::processGamepadButton(Event &event) {}
void Input::processGamepadAxis(Event &event) {}

} // namespace input
} // namespace engine
