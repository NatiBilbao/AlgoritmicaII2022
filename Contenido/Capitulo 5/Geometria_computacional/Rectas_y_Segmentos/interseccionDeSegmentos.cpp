bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);

    if((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&
      ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))
           return true;

    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}
