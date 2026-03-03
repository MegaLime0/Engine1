#pragma once

namespace engine {
namespace math {

class Vector2D {
    public:
        Vector2D(float x, float y);
        Vector2D(Vector2D &other);

        Vector2D operator+(const Vector2D &other) const;
        Vector2D operator-(const Vector2D &other) const;

        void operator+=(const Vector2D &other);
        void operator-=(const Vector2D &other);

        Vector2D operator*(const Vector2D &other) const;
        Vector2D operator/(const Vector2D &other) const;

        void operator*=(const Vector2D &other);
        void operator/=(const Vector2D &other);

        float length() const;
        float dot(Vector2D &other) const;
        float distance(Vector2D &other) const;

        void normalize();
        Vector2D normalized() const;

    private:
        float x, y;
};

} // namespace math
} // namespace engine
