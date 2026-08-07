#pragma once

#include "engine/asset_container.hpp"
#include "engine/render/shader.hpp"
#include "engine/render/texture_2d.hpp"

namespace Engine {
namespace Render {

struct Material {
    AssetHandler<Texture2D> diffuseMap;
    AssetHandler<Texture2D> normalMap;
    Shader* shader = nullptr;
};

} // namespace Engine
} // namespace Render
