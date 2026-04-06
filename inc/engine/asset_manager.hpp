#pragma once 

#include <engine/asset_container.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/base_texture.hpp>

namespace engine {

struct AssetManager {
    AssetContainer shaders;
    AssetContainer textures;
};

} // namespace engine
