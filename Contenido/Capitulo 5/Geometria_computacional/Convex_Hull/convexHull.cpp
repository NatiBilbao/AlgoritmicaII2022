vector <Point> convexHull(vector <Point> P){
    //Ordenamineto lexicografico
    sort(P.begin(), P.end());

    int n = P.size(), k = 0;
    Point H[2*n];

    //Mitad inferior
    for(int i = 0; i < n; ++i){
        while(k >= 2 && area(H[k-2], H[k-1], P[i] <= 0) --k);
        H[k++] = P[i];
    }

    //Mitad superior
    for(int i = n -2, t = k; i >= 0; --i) {
        while (k >= t && area(H[k - 2], H[k - 1], P[i] <= 0)--k);
        H[k++] = P[i];
    }

    return vector <Point> (H, H+k-1);
}