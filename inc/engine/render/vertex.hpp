#pragma once

#include <engine/math/vector2d.hpp>
#include <engine/math/vector3d.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Engine {
namespace Render {

struct SpriteVertex {
    glm::vec2 pos;
    glm::vec2 uv;
    glm::vec3 color;
};

struct TileVertex {
    glm::vec3 pos;
    glm::vec2 uv;
    glm::vec3 color;
    float textureIndex;
};

} // namespace Render
} // namespace Engine
