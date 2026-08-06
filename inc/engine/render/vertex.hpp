#pragma once

#include "engine/math/vector2d.hpp"
#include "engine/math/vector3d.hpp"
namespace Engine {
namespace Render {

struct SpriteVertex {
    Math::Vector2D pos;
    Math::Vector2D uv;
    Math::Vector3D color;
};

struct TileVertex {
    Math::Vector2D pos;
    Math::Vector2D uv;
    Math::Vector3D color;
    float textureIndex;
};

} // namespace Render
} // namespace Engine
