Vector2D operator+( const Vector2D& left, const Vector2D& right){
    return Vector2D(left.x + right.x, left.y + right.y);
}

Vector2D operator*( float scale, const Vector2D& vector){
    return Vector2D( scale * vector.x, scale * vector.y );
}

Vector2D operator*( const Vector2D& vector, float scale ){
    return scale * vector;
}

Vector2D& Vector2D::operator+=(const Vector2D& right){

    x += right.x;
    y += right.y;

    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& right){

    x -= right.x;
    y -= right.y;

    return *this;
}
