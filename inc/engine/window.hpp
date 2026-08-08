#pragma once

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_events.h>
#include <engine/configs.hpp>
#include <string>

namespace Engine {

using Event = SDL_Event;

class Window {
    public:
        Window(int width, int height, std::string title, bool fullscreen, bool vsync);
        Window(Config::Window wConf);

        ~Window();

        void makeFullscreen();
        void makeWindowed();

        void getWindowConfig();

        void swapBuffers();

        bool pollEvents(Event &event);

    private:
        void updateWindowFlags();

        Config::Window _wConf;
        SDL_Window* _window;
        SDL_GLContext _glContext;
};

}
