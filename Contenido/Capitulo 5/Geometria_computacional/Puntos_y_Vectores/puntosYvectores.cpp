#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point{
    double x,y;
    Point(){}
    Point(double a, double b){x = a; y = b;}
    double mod2() {return x*x + y*y;}
    double mod() {return sqrt(x*x + y*y);}
    double arg() {return atan2(y,x);}
    Point ort() {return  Point(-y,x);}
    Point unit() {double k = mod(); return Point(x/k, y/k);}
};

Point operator +(const Point &a, const Point &b) {return Point(a.x + b.x, a.y + b.y);}
Point operator -(const Point &a, const Point &b) {return Point(a.x + b.x, a.y + b.y);}
Point operator /(const Point &a, double k) {return  Point(a.x/k, a.y/k);}
Point operator *(const Point &a, double k) {return  Point(a.x*k, a.y*k);}

bool operator == (const Point &a, const Point &b){
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator != (const Point &a, const Point &b){
    return !(a==b);
}
bool operator < (const Point &a, const Point &b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
