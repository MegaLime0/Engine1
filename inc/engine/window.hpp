#pragma once
#include <SDL3/SDL_video.h>
#include <string>

namespace engine {

struct WindowConfig {
    int width, height;
    std::string title;
    SDL_WindowFlags flags;
};

class Window {
    public:
        Window();
        Window(WindowConfig wConf);

        ~Window();

        void resize();
        void makeFullscreen();
        void makeWindowed();

        void swapBuffers();

    private:
        WindowConfig _wConf;
        SDL_Window* _window;
        SDL_GLContext _glContext;
};

}

