#pragma once

namespace Engine {
namespace Math {

class Vector3D {
    public:
        Vector3D(float x, float y, float z);
        Vector3D(Vector3D &other);

        Vector3D operator+(const Vector3D &other) const;
        Vector3D operator-(const Vector3D &other) const;

        void operator+=(const Vector3D &other);
        void operator-=(const Vector3D &other);

        Vector3D operator*(const Vector3D &other) const;
        Vector3D operator/(const Vector3D &other) const;

        void operator*=(const Vector3D &other);
        void operator/=(const Vector3D &other);

        float length() const;
        float dot(Vector3D &other) const;
        float distance(Vector3D &other) const;

        void normalize();
        Vector3D normalized() const;

    private:
        float x, y, z;
};

} // namespace Math
} // namespace Engine
