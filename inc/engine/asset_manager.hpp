#pragma once

#include <string>
#include <vector>
#include <queue>
#include <glad/glad.h>
#include <engine/shader.hpp>
#include <engine/texture_2d.hpp>
#include <engine/tilemap.hpp>

namespace engine {

struct ShaderID { size_t value; };
struct TextureID { size_t value; };
struct TileMapID { size_t value; };

// TODO: figure out a way to load/unload textures here

class AssetManager {
    public:
        AssetManager();
        ~AssetManager();

        ShaderID loadShader(std::string vPath, std::string fPath);
        void unloadShader(ShaderID id);

        TextureID loadTexture(std::string tPath);
        void unloadTexture(TextureID id);

        TileMapID loadTileMap(std::string tmPath);
        void unloadTileMap(TileMapID id);

    private:
        // implement swap and pop
        std::vector<Shader> shaders;
        std::queue<unsigned int> shaderSlots;

        std::vector<Texture2D> textures;
        std::queue<unsigned int> textureSlots;

        std::vector<TileMap> tilemaps;
        std::queue<unsigned int> tilemapSlots;
};

}
