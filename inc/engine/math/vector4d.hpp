#pragma once

namespace Engine {
namespace Math {

class Vector4D {
    public:
        Vector4D(float x, float y, float z, float w);
        Vector4D(Vector4D &other);

        Vector4D operator+(const Vector4D &other) const;
        Vector4D operator-(const Vector4D &other) const;

        void operator+=(const Vector4D &other);
        void operator-=(const Vector4D &other);

        Vector4D operator*(const Vector4D &other) const;
        Vector4D operator/(const Vector4D &other) const;

        void operator*=(const Vector4D &other);
        void operator/=(const Vector4D &other);

        float length() const;
        float dot(Vector4D &other) const;
        float distance(Vector4D &other) const;

        void normalize();
        Vector4D normalized() const;

    private:
        float x, y, z, w;
};

} // namespace Math
} // namespace Engine
