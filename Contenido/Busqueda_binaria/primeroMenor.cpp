#include <bits/stdc++.h>

using namespace std;
int n;
int x;
int A[100000];
bool f(int number) {
    return number <= x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    int mid = (ini + fin) / 2;
    int pos = -1;
    while(ini <= fin ) {
        if(f(A[mid])) {  // Modificar la funcion de condicion
            pos = mid;
            ini = mid + 1;

        } else {
            fin = mid - 1;
        }
        mid = (ini + fin) / 2;
    }
    if(f(A[pos])) {
        cout<<A[pos]<<endl;
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
