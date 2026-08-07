#pragma once 

#include "engine/configs.hpp"
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Engine {
namespace Render {

class Camera2D {
    public:
        Camera2D(Config::Camera2D config, glm::vec2 screenDimensions, glm::vec2 position);

        glm::vec2 getDimensions() { return dimensions; }
        void setDimensions(glm::vec2 dimensions) { this->dimensions = dimensions; }

        float getZoom() { return zoom; }
        void changeZoom(float zoom) { this->zoom = zoom; }
        void relativeZoom(float deltaZoom) { zoom += deltaZoom; }

        glm::mat4 getViewProjection();
        void setPosition(glm::vec2 newPos);
        void advancePosition(glm::vec2 direction, float magnitude);
        void advancePosition(glm::vec2 velocity);

    private:
        // how much of the game world units the camera can see
        glm::vec2 dimensions;
        // higher zoom = closer
        float zoom;

        // camera position in world space
        glm::vec2 position;
};

} // namespace Render
} // namespace Engine
