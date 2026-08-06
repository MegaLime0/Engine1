#pragma once 

#include "engine/render/texture_2d.hpp"
#include "engine/render/texture_2d_array.hpp"
#include <engine/asset_container.hpp>
#include <engine/render/shader.hpp>

namespace Engine {

class AssetManager {
    AssetContainer<Render::Shader> shaders;
    AssetContainer<Render::Texture2D> texture2ds;
    AssetContainer<Render::Texture2DArray> texture2darrays;
};

} // namespace Engine
