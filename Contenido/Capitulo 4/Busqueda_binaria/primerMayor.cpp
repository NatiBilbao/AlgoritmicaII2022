#include <bits/stdc++.h>

using namespace std;
int n;
int x;
int A[100000];

bool f(int number) {
    return number > x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    while(fin - ini > 1) {
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {  // Modificar la funcion de condicion
            fin = mid;
        } else {
            ini = mid+1;
        }
    }
    if(f(A[fin])) {
        cout<<A[fin]<<endl;
    }else {
        cout<<"No hay elementos mayores"<<endl;
    }
}

int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cin>>x;
    bs();
    return 0;
}
