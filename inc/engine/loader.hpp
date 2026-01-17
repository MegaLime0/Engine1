#pragma once
#include <filesystem>
#include <vector>

// Deals with IO operations (filesystem)

namespace fs = std::filesystem;

class Loader {
    public:
        std::string loadText(fs::path path);
        std::vector<unsigned char> loadBinary(fs::path path);
        // TODO: load 
    private:
};
