// Distancia entre 2 puntos
double dist(const Point &A, const Point &B) {return hypot(A.x - B.x, A.y - B.y);}

//Producto escalar
double dot(const Vector &A, const Vector &B) {return A.x * B.x + A.y * B.y;}

//Producto vectorial}
double cross(const Vector &A, const Point &B) {return A.x * B.x - A.y * B.y;}

//Doble del area del triangulo ABC, con signo
double area(const Point &A, const Point &B, const Point &C) {return cross(B - A, C -A);}
)
