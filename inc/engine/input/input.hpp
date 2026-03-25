#pragma once



#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_scancode.h>
#include <engine/math/vector2d.hpp>
#include <engine/window.hpp>
#include <SDL3/SDL_events.h>
#include <map>
#include <queue>
#include <vector>

namespace engine {
namespace input {

// Handles input/events or smething
// Should use buffering
using Event = SDL_Event;
using Action = const char*;

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

        void bindAction(Action action, SDL_Scancode keycode);
        void unbindAction(Action action);

        // take inputActionMap and swap keys and values
        void buildActionMap();

    private:
        math::Vector2D _mousePos;

        std::map<Action, std::vector<SDL_Scancode>> inputActionMap;
        std::map<SDL_Scancode, Action> inputLookup;
        // created by buildActionMap()
        // TODO: implement queue
        // TODO: use hashmap for binding keys to enums, and
        // another hashmap for enums to actions
        // Input Buffer

        // Merge inputs together into one "block"
};

} // namespace input
} // namespace engine
