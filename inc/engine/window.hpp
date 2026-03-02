#pragma once

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_events.h>
#include <string>

namespace engine {

using Event = SDL_Event;

struct WindowConfig {
    int width, height;
    std::string title;
    SDL_WindowFlags flags;
};

class Window {
    public:
        Window(int width, int height, std::string title, SDL_WindowFlags flags);
        Window(WindowConfig wConf);

        ~Window();

        void makeFullscreen();
        void makeWindowed();

        void getWindowConfig();

        void swapBuffers();

        bool pollEvents(Event &event);

    private:
        void updateWindowFlags();

        WindowConfig _wConf;
        SDL_Window* _window;
        SDL_GLContext _glContext;
};

}

