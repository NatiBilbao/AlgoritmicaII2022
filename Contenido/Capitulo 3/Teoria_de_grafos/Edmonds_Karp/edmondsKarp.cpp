#include <bits/stdc++.h>
#define MAX_N 101

using namespace std;

int grafo[MAX_N][MAX_N];
int path[MAX_N];

int maxFlow(int s,int t) {
    int maxFlow = 0;
    while(true) {

        memset(path, -1, sizeof(path));
        queue<int> Q;
        Q.push(s);
        path[s] = s;
        while(!Q.empty() && path[t]==-1) {
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++) {
                if(path[i]==-1 && grafo[currentNode][i] > 0) {
                    path[i] = currentNode;
                    Q.push(i);
                }
            }
        }
        int minFlow = 1e9;
        if(path[t]==-1) {
            break;
        }
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]);
        }

        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            grafo[to][from] += minFlow;
            grafo[from][to] -= minFlow;
        }

        maxFlow += minFlow;

    }
    return maxFlow;
}

int main() {
    int vertices, nroCases = 1;
    while(cin>>vertices && vertices) {
        int s,t,aristas;
        cin>>s>>t>>aristas;
        memset(grafo,0,sizeof(grafo));
        for(int i=0;i<aristas;i++) {
            int from, to, capacity;
            cin>>from>>to>>capacity;
            grafo[from][to] = capacity;
            grafo[to][from] = 0;
        }
        cout<<maxFlow(s,t)<<endl;
    }
}