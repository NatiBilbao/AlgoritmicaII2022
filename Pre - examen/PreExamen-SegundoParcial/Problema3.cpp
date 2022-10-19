#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int numeroEtiquetas; // n del vector
int persona;          //
int etiquetas[100000];

bool f(int k) {
    int ultimaPersona = 0;
    int actualPersona = 1;
    int numeroPersona = 1;
    while(actualPersona < numeroEtiquetas) {
        if(etiquetas[actualPersona] - etiquetas[ultimaPersona] >= k) {
            numeroPersona++;
            ultimaPersona = actualPersona;
        }
        actualPersona++;
        if(numeroPersona == persona) {
            return true;
        }
    }
    return false;
}

int bs() {
    long long inicio  = 0;
    long long final = etiquetas[numeroEtiquetas - 1];
    long long respuesta = 0;
    while(inicio < final - 1 ) {
        long long mid = inicio + (final - inicio) / 2;
        if(f(mid)) {
            respuesta = mid;
            inicio = mid;
        }
        else{
            final = mid;
        }
    }
    return respuesta;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin >> numeroEtiquetas >> persona;
        for(int i=0;i<numeroEtiquetas;i++) {
            cin>>etiquetas[i];
        }
        sort(etiquetas,etiquetas+numeroEtiquetas);
        cout<<bs()<<endl;
    }
}
