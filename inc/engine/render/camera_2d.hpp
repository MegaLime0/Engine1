#pragma once 

#include <glm/ext/matrix_float4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Engine {
namespace Render {

class Camera2D {
    public:
        Camera2D();

        glm::mat4 getViewProjection();
        void setPosition(glm::vec2 newPos);
        void advancePosition(glm::vec2 direction, float magnitude);
        void advancePosition(glm::vec2 velocity);

    // TODO: implement
    // need to model view projection matrix type shi
    private:
        glm::vec2 position;
        glm::mat4 viewMat;
        glm::mat4 projMat;
        glm::mat4 transform;
};

} // namespace Render
} // namespace Engine
