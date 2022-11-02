double cross(const Vector &A, const Vector &B) {return A.x * B.y - A.y * B.x;}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D){
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C))
};
