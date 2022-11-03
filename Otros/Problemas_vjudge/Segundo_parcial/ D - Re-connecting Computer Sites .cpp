#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MAXN 1000003

using namespace std;

int pr[MAXN];

int econtrarConjunto(int r){
    if(pr[r] == r) return r;
    return econtrarConjunto(pr[r]);
}

void crearConjunto(int n){
    for(int i = 0; i < n; i++)
        pr[i] = i;
}

struct Borde{

    int u, v, w;

    bool operator<(const Borde &p) const{
        return w < p.w;
    }
};

vector<Borde> e;

int Kruskal(int n){

    sort(e.begin(), e.end());

    crearConjunto(n);

    int count = 0, sum = 0;
    for(int i = 0; i < (int)e.size(); i++){
        int u = econtrarConjunto(e[i].u);
        int v = econtrarConjunto(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            count++;
            sum += e[i].w;
            if(count==n-1)
                break;
        }
    }
    return sum;
}

int main(){
    int n, k, m;
    bool flag=true;

    while(scanf("%d", &n)==1){
        int costoInicial = 0;
        e.clear();
        for(int i = 0; i < n-1; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            costoInicial += w;
        }
        cin>>k;
        for(int i = 0; i < k; i++) {
            int u, v, w;
            cin>>u>>v>>w;
            Borde data;
            data.u = u;
            data.v = v;
            data.w = w;
            e.push_back(data);
        }
        cin>>m;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin>>u>>v>>w;
            Borde data;
            data.u = u;
            data.v = v;
            data.w = w;
            e.push_back(data);
        }
        n = k + m;
        int res = Kruskal(n);
        if(!flag) printf("\n");
        flag = false;
        cout<<costoInicial<<endl;
        cout<<res<<endl;
    }

    return 0;
}