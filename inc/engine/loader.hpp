#pragma once
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
namespace engine {
// Deals with IO operations (filesystem)


class Loader {
    public:
        static std::string loadText(fs::path path);
        static std::vector<unsigned char> loadBinary(fs::path path);
        static std::vector<unsigned char> loadImage(fs::path path, int &w, int &h, int &channels);
};

}
