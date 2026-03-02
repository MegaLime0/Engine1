#pragma once 

#include <engine/asset_container.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/base_texture.hpp>

namespace engine {

class AssetManager {
    public:
        AssetContainer<render::Shader> shaders;
        AssetContainer<render::BaseTexture> textures;
};

} // namespace engine
