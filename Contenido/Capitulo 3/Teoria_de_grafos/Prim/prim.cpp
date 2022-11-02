#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > grafo[100000];
bool visitados[100000];

int Prim(int verticeInicial){
    multiset<pair<int, int>> colaPrioridad;
    colaPrioridad.insert(make_pair(0, verticeInicial));
    int answer = 0;
    while (!colaPrioridad.empty()){
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin());

        int vertice = verticeActual.second;
        int peso = verticeActual.first;

        if (!visitados[vertice]){
            visitados[vertice] = true;
            answer += peso;
            for (int i = 0; i < grafo[vertice].size(); ++i){
                int verticeVecino = grafo[vertice][i].second;
                int pesoVecino = grafo[vertice][i].first;
                colaPrioridad.insert(make_pair(pesoVecino, verticeVecino));
            }
        }
    }

    return answer;
}

int main()
{
    int vertices, aristas;
    cin >> vertices >> aristas;
    for (int i = 0; i < aristas; i++)
    {
        int ini,fin,peso;
        cin>>ini>>fin>>peso;
        grafo[ini].push_back(make_pair(peso,fin));
        grafo[fin].push_back(make_pair(peso,ini));
    }
    cout <<  Prim(0) << endl;
    return 0;
}
