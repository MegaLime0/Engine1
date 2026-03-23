#pragma once



#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_scancode.h>
#include <engine/math/vector2d.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>
#include <map>
#include <queue>

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

        std::map<SDL_Scancode, const char*> inputMap;
        std::map<const char*, const char*> actionMap;
        // TODO: implement queue
        std::queue<int> inputQueue;
        // TODO: use hashmap for binding keys to enums, and
        // another hashmap for enums to actions
        // Input Buffer

        // Merge inputs together into one "block"
};

} // namespace input
} // namespace engine
