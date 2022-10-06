#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_V 100000

int n,m,numComp;
int parent[MAX_V],rank[MAX_V];

void init(){
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        rank[i] = 0;
    }

    numComp = n;
}

int find(int v){
    if(parent[v] == v)
        return v;
    parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int u, int v){
    int pu = find(u), pv = find(v);
    if(pu == pv)
        return;
    --numComp;

    if(rank[pu] < rank[pv]) parent[pu] = pv;
    else{
        parent[pv] = pu;
        if(rank[pu] == rank[pv]) ++rank[pu];
    }
}

#define MAX_E 100000

int eu[MAX_E],ev[MAX_E];
int q,ind[MAX_E],ans[MAX_E];
bool add[MAX_E];

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i)
        scanf("%d %d", &eu[i], &ev[i]);

    scanf("%d",&q);
    memset(add,true,sizeof(add));

    for(int i = 0; i < q; ++i){
        scanf("%d",&ind[i]);
        add[--ind[i]] = false;
    }

    init();

    for(int i = 0; i < m; ++i){
        if(!add[i])
            continue;
        Union(eu[i], ev[i]);
    }

    for(int i = q - 1; i >= 0; --i){
        ans[i] = numComp;
        Union(eu[ind[i]], ev[ind[i]]);
    }

    printf("%d",ans[0]);
    for(int i = 1; i < q; ++i) printf(" %d", ans[i]);
    printf("\n");

    return 0;
}