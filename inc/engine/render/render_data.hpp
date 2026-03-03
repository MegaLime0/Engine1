#pragma once

#include <vector>
namespace engine {
namespace render {

struct RenderData {
    std::vector<float> vertices; 
    std::vector<unsigned int> indices;
    bool normalized;
};


} // namespace render
} // namespace engine
