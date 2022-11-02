bool isConvex(const vector <Point> &P){
    int n = P.size(), pos = 0, neg = 0;
    for(int i=0; i<n; i++){
        double A = area(P[i], P[(i+1)%n], P[(i+2)%n]);
        if(A < 0) neg++;
        else if(A > 0) pos++;
    }

    return neg == 0 || pos == 0;
}