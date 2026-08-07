#include <engine/engine.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <glad/glad.h>
#include <iostream>
#include <glm/vec2.hpp>

int main() {

    Engine::Engine game;

    // Engine::AssetManager am;
    // Engine::Window window(800, 600, "Temp", SDL_WINDOW_OPENGL);

    while (true) {
        game.update();
    }


    std::cout << "Hello World!" << std::endl;
}
