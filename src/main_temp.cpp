#include "engine/configs.hpp"
#include "engine/render/camera_2d.hpp"
#include <engine/engine.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <glad/glad.h>
#include <iostream>
#include <glm/vec2.hpp>

int main() {

    Engine::Engine game;

    while (true) {
        game.update();
    }

    std::cout << "Hello World!" << std::endl;
}
