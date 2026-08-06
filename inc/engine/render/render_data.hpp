#pragma once

#include <vector>

namespace Engine {
namespace Render {

struct RenderData {
    std::vector<float> vertices; 
    std::vector<unsigned int> indices;
    bool normalized;
};


} // namespace Render
} // namespace Engine
