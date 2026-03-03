#include <engine/math/vector2d.hpp>
#include <cmath>

namespace engine {
namespace math {

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(Vector2D &other) {
    this->x = other.x;
    this->y = other.y;
}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return Vector2D(x - other.x, y - other.y);
}

void Vector2D::operator+=(const Vector2D &other) {
    this->x += other.x;
    this->y += other.y;
}

void Vector2D::operator-=(const Vector2D &other) {
    this->x -= other.x;
    this->y -= other.y;
}

Vector2D Vector2D::operator*(const Vector2D &other) const {
    return Vector2D(x * other.x, y * other.y);
}

Vector2D Vector2D::operator/(const Vector2D &other) const {
    return Vector2D(x / other.x, y / other.y);
}

void Vector2D::operator*=(const Vector2D &other) {
    this->x *= other.x;
    this->y *= other.y;
}
void Vector2D::operator/=(const Vector2D &other) {
    this->x /= other.x;
    this->y /= other.y;
}

float Vector2D::length() const {
    float lengthSquared = this->x * this->x + this->y * this->y;

    if (lengthSquared > 0) {
        return std::sqrt(lengthSquared);
    }

    return -1;
}

float Vector2D::distance(Vector2D &other) const {
    float xDiff = this->x - other.x;
    float yDiff = this->y - other.y;

    float distSquared = xDiff * xDiff + yDiff * yDiff;

    if (distSquared > 0) {
        return std::sqrt(distSquared);
    }

    return -1;
}

float Vector2D::dot(Vector2D &other) const {
    float interValue = this->x * other.x + this->y + other.y;

    if (interValue >= 0) {
        return std::sqrt(interValue);
    }

    return -1;
}

void Vector2D::normalize() {
    float len = length();

    this->x /= len;
    this->y /= len;
}

Vector2D Vector2D::normalized() const {
    float len = length();
    return Vector2D(this->x / len, this->y / len);
}

} // namespace math
} // namespace engine
