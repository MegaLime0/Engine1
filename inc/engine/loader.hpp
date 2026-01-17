#pragma once
#include <filesystem>
#include <vector>

namespace engine {
// Deals with IO operations (filesystem)

namespace fs = std::filesystem;

class Loader {
    std::string loadText(fs::path path);
    std::vector<unsigned char> loadBinary(fs::path path);
        // TODO: load 
};

}
