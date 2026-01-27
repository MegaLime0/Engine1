#pragma once
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
namespace engine {
// Deals with IO operations (filesystem)


class Loader {
    static std::string loadText(fs::path path);
    static std::vector<unsigned char> loadBinary(fs::path path);
        // TODO: load 
};

}
