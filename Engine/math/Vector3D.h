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

    };

    inline Vector3D operator+( const Vector3D& left, const Vector3D& right);
    inline Vector3D operator*( float scale, const Vector3D& vector);
    inline Vector3D operator*( const Vector3D& vector, float scale );



    #include "Vector3D.inl"
}


#endif // VECTOR3D_H
