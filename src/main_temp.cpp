#include "engine/asset_manager.hpp"
#include "engine/window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <glad/glad.h>
#include <iostream>

int main() {

    engine::AssetManager am;
    engine::Window window(800, 600, "Temp", SDL_WINDOW_OPENGL);


    SDL_Event events;
    window.pollEvents(events);

    std::cout << "Hello World!" << std::endl;
}
