#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

void printPath(vector<vector<int>> const &path, int v, int u){
    if (path[v][u] == v){
        return;
    }
    printPath(path, v, path[v][u]);
    cout << path[v][u] << ", ";
}

void printSolution(vector<vector<int>> const &cost, vector<vector<int>> const &path){
    int n = cost.size();
    for (int v = 0; v < n; v++){
        for (int u = 0; u < n; u++){
            if (u != v && path[v][u] != -1){
                cout << "El camino más corto desde " << v << " —> " << u << " is ["
                     << v << ", ";
                printPath(path, v, u);
                cout << u << "]" << endl;
            }
        }
    }
}

void floydWarshall(vector<vector<int>> const &adjMatrix){
    int n = adjMatrix.size();

    if (n == 0){
        return;
    }

    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n));

    for (int v = 0; v < n; v++){
        for (int u = 0; u < n; u++){
            cost[v][u] = adjMatrix[v][u];

            if (v == u){
                path[v][u] = 0;
            } else if (cost[v][u] != INT_MAX){
                path[v][u] = v;
            } else {
                path[v][u] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++){
        for (int v = 0; v < n; v++){
            for (int u = 0; u < n; u++){

                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u]){
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            if (cost[v][v] < 0){
                cout << "Ciclo de peso negativo encontrado!!";
                return;
            }
        }
    }

    printSolution(cost, path);
}

int main(){

    int I = INT_MAX;

    vector<vector<int>> adjMatrix =
            {
                    { 0, I, -2, I },
                    { 4, 0, 3, I },
                    { I, I, 0, 2 },
                    { I, -1, I, 0 }
            };

    floydWarshall(adjMatrix);

    return 0;
}
