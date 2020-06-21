Vector3D operator+( const Vector3D& left, const Vector3D& right){
    return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z );
}

Vector3D operator-( const Vector3D& left, const Vector3D& right){
    return Vector3D(left.x - right.x, left.y - right.y, left.z - right.z );
}

Vector3D operator*( float scale, const Vector3D& vector){
    return Vector3D( scale * vector.x, scale * vector.y, scale * vector.z );
}

Vector3D operator*( const Vector3D& vector, float scale ){
    return scale * vector;
}

Vector3D& Vector3D::operator+=(const Vector3D& right){

    x += right.x;
    y += right.y;
    z += right.z;

    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& right){

    x -= right.x;
    y -= right.y;
    z -= right.z;

    return *this;
}
