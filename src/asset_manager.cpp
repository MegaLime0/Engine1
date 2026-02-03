#include <engine/asset_manager.hpp>
#include <engine/shader.hpp>
#include <engine/tilemap.hpp>

namespace engine {

    AssetManager::AssetManager() {
        // TODO: init logic if necessary
    }

    AssetManager::~AssetManager() {
        // TODO: desctruction logic
    }

    ShaderID AssetManager::loadShader(std::string vPath, std::string fPath) {
        if (!shaderSlots.empty()) {
            unsigned int shaderIndex = shaderSlots.back();
            shaderSlots.pop();
            shaders.at(shaderIndex) = Shader(vPath, fPath);

            ShaderID id = { shaderIndex };
            return id;
        } else {
            unsigned int shaderIndex = shaders.size() - 1;
            shaders.at(shaderIndex) = Shader(vPath, fPath);

            ShaderID id = { shaderIndex };
            return id;
        }
    }

    void AssetManager::unloadShader(ShaderID id) {
        shaders.at(id.value).deleteProgram();
        shaderSlots.push(id.value);
    }

    // TODO: proper texture loading
    TextureID AssetManager::loadTexture(std::string tPath) {
        if (!textureSlots.empty()) {
            unsigned int textureIndex = textureSlots.back();
            textureSlots.pop();
            textures.at(textureIndex) = Texture2D(tPath);

            TextureID id = { textureIndex };
            return id;
        } else {
            unsigned int shaderIndex = shaders.size() - 1;
            textures.at(shaderIndex) = Texture2D(tPath);

            TextureID id = { shaderIndex };
            return id;
        }
    }

    void AssetManager::unloadTexture(TextureID id) {
        textures.at(id.value).deleteTexture();
        textureSlots.push(id.value);
    }

    // TODO: implement tilemap load/unload tilemap
};
