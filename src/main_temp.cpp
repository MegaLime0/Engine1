#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error("Couldn't initialize video");
    }

    std::cout << "Hello World!" << std::endl;
}
