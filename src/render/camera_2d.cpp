#include "engine/configs.hpp"
#include <engine/render/camera_2d.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace Engine {
namespace Render {

Camera2D::Camera2D(Config::Camera2D config, glm::vec2 screenDimensions) {
    this->dimensions = { 
        config.visibleWidth, 
        config.visibleWidth / (screenDimensions.x / screenDimensions.y) 
    };
    this->zoom = config.defaultZoom;
}


glm::mat4 Camera2D::getViewProjection() {
    glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(-position, 1.0f));
    glm::mat4 projectionMat = glm::ortho(
            -dimensions.x / 2 / zoom, 
            dimensions.x / 2 / zoom, 
            -dimensions.y / 2 / zoom,
            dimensions.y / 2 / zoom,
            -1.0f, 1.0f
        );

    return projectionMat * viewMat;
}

void Camera2D::setPosition(glm::vec2 newPos) {
    position = newPos;
}

void Camera2D::advancePosition(glm::vec2 direction, float magnitude) {
    position += direction * magnitude;
}

void Camera2D::advancePosition(glm::vec2 velocity) {
    position += velocity;
}



} // namespace Render
} // namespace Engine
