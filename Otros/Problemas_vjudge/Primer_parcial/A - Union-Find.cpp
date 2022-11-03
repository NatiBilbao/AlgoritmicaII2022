#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_SIZE 1000000

using namespace std;

int parent[MAX_SIZE];
int rango[MAX_SIZE];

void init (int n){
    for (int i=0; i<n; i++){
        parent[i] = i;
    }
    for (int i=0; i<n; i++){
        rango[i] = 0;
    }
}
int find (int x){
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}
bool sameSet (int i, int j) {
    return find (i) == find (j);
}
void join (int v1, int v2) {
    if (sameSet (v1,v2))
        return;
    int parentV1 = find(v1), parentV2 = find (v2);
    if (parentV1 != parentV2){
        if(rango[parentV1]> rango[parentV2])
            parent[parentV2] = parentV1;
        else{
            parent[parentV1]=parentV2;
            if(rango[parentV1] == rango[parentV1]) rango[parentV1]++;
        }
    }
}
int main () {

    int N, Q, a, b;
    char c;

    scanf("%d%d", &N, &Q);

    init (N);
    for (int i=0; i < Q; i++){
        scanf(" %C%d%d", &c, &a, &b);
        if(c =='='){
            join (a, b);
        }
        else{
            if(sameSet (a, b))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
