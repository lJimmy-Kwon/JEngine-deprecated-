#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>

namespace Math{

    struct Vector3D{
        float x;
        float y;
        float z;

        explicit Vector3D( float x = 0.0f, float y = 0.0f, float z = 0.0f ) :
            x(x), y(y), z(z){}
        inline Vector3D& operator+=( const Vector3D& right );
        inline Vector3D& operator-=( const Vector3D& right );
        inline Vector3D perpCwXy()  const;
        inline Vector3D perpCcwXy() const;
        inline float dot( const Vector3D& other ) const;
        inline float magnitude() const;
        inline float magnitudeSquared() const;
        inline Vector3D normalized() const;
        inline Vector3D projectOnto(const Vector3D& target ) const;

    };

    inline Vector3D operator+( const Vector3D& left, const Vector3D& right );
    inline Vector3D operator-( const Vector3D& left, const Vector3D& right );
    inline Vector3D operator*( float scale, const Vector3D& vector );
    inline Vector3D operator*( const Vector3D& vector, float scale );
    inline Vector3D lerp(float alpha, const Vector3D& source, const Vector3D& target );



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

    float Vector3D::magnitude() const{

        return sqrt(this->dot(*this));

    }

    float Vector3D::magnitudeSquared() const
    {
        return this->dot(*this);
    }

    Vector3D Vector3D::normalized() const
    {
        float inverseMagnitude = 1.0f / magnitude();
        return inverseMagnitude * (*this);
    }

    Vector3D Vector3D::projectOnto(const Vector3D &target) const
    {
        return (this->dot(target) / target.magnitudeSquared()) * target;
    }

    Vector3D lerp(float alpha, const Vector3D& source, const Vector3D& target ){
        return (1.0f - alpha ) * source + alpha * target;
    }

    #include "Vector3D.inl"
}


#endif // VECTOR3D_H
