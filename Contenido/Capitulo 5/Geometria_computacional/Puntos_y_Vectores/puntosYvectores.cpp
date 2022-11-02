#define Vector Point

struct Point{
    double x,y;
    Point(){}
    Point(double a, double b){x = a; y = b;}
};

// Declaracion

Point A(2,4);

Point B(1,-1);

Vector V(0,10);
