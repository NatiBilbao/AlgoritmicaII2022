bool onSegment(const Point &A, const Point &B, const Point &P){
    return abs(area(A, B, P)) < EPS &&
           P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
           P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}
