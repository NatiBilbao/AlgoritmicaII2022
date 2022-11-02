double area(const vector <Point> &P){
    int n = P.size();
    double A = 0;
    for(int i = 1; i <= n -2; i++){
        A += area(P[0], P[i], P[i+1]);
        return abs(A/2);
    }
}
