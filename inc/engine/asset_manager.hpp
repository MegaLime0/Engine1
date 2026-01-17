#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>

namespace engine {

struct ShaderID { unsigned int value; };
struct TextureID { unsigned int value; };
struct TileMapID {unsigned int value; };

// TODO: figure out a way to load/unload textures here
struct Texture {
    GLuint glID;
    bool isValid;
};

class AssetManager {
    public:
        AssetManager();

        ShaderID loadShader(std::string vPath, std::string fPath);
        TextureID loadTexture(std::string tPath);

    private:
        std::vector<Texture> textures;
        std::vector<unsigned int> textureSlots;
};

}
