#include <engine/engine.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <glad/glad.h>
#include <iostream>

int main() {

    Engine::Engine game;

    // engine::AssetManager am;
    // engine::Window window(800, 600, "Temp", SDL_WINDOW_OPENGL);

    while (true) {
        game.update();
    }


    std::cout << "Hello World!" << std::endl;
}
