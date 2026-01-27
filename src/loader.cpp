#include <engine/loader.hpp>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace engine {

std::string Loader::loadText(fs::path path) {
    if (!fs::exists(path)) {
        throw std::runtime_error("File doesn't exist: " + std::string(path));
    }

    std::ifstream file(path);
    return "";
}

std::vector<unsigned char> Loader::loadBinary(fs::path path) {
    if (!fs::exists(path)) {
        throw std::runtime_error("File doesn't exist: " + std::string(path));
    }

    return {0} ; 
}

}
