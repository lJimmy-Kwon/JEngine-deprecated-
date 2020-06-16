#ifndef VECTOR3D_H
#define VECTOR3D_H

namespace Math{
    struct Vector3D{
        float x;
        float y;
        float z;

        explicit Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
            x(x), y(y), z(z){}
        inline Vector3D& operator+=(const Vector3D& right);
        inline Vector3D& operator-=(const Vector3D& right);
        inline Vector3D perpCwXy() const;
        inline Vector3D perpCcwXy() const;
        inline float dot(const Vector3D& other ) const;

    };

    inline Vector3D operator+( const Vector3D& left, const Vector3D& right);
    inline Vector3D operator-( const Vector3D& left, const Vector3D& right);
    inline Vector3D operator*( float scale, const Vector3D& vector);
    inline Vector3D operator*( const Vector3D& vector, float scale );

    Vector3D Vector3D::perpCwXy() const
    {
        return Vector3D( y, -x );
    }


    Vector3D Vector3D::perpCcwXy() const
    {
        return Vector3D( -y, x );
    }

    float Vector3D::dot(const Vector3D &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    #include "Vector3D.inl"
}


#endif // VECTOR3D_H
