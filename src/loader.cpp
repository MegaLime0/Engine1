#include <engine/loader.hpp>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Engine {

std::string Loader::loadText(fs::path path) {
    if (!fs::exists(path)) {
        throw std::runtime_error("File doesn't exist: " + std::string(path));
    }

    std::ifstream file {path, std::ios::in}; 
    std::string text {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    return text; 
}

std::vector<unsigned char> Loader::loadBinary(fs::path path) {
    if (!fs::exists(path)) {
        throw std::runtime_error("File doesn't exist: " + std::string(path));
    }

    std::ifstream file {path, std::ios::in | std::ios::binary};
    std::vector<unsigned char> binary { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    return binary;
}

std::vector<unsigned char> Loader::loadImage(fs::path path, int &w, int &h, int &channels) {
    if (!fs::exists(path)) {
        throw std::runtime_error("File doesn't exist: " + std::string(path));
    }

    unsigned char *raw_data = stbi_load(path.c_str(), &w, &h, &channels, 0);

    if (!raw_data) {
        throw std::runtime_error("Couldn't load image: " + std::string(path));
    }

    size_t length = w * h * channels;
    std::vector<unsigned char> data {raw_data, raw_data + length};

    return data;
}

}
