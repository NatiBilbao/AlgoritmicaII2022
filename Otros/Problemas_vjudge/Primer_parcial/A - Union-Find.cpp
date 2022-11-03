#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:

    UnionFind(int size) {
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
        }
    }

    int get_set(int n) {
        if (parent[n] == n) return n;

        int res = get_set(parent[n]);
        parent[n] = res;

        return res;
    }

    bool is_same_set(int n, int m) {
        return get_set(n) == get_set(m);
    }

    void join_set(int n, int m) {
        int set_of_n = get_set(n);
        parent[set_of_n] = get_set(m);
    }

private:
    vector<int> parent;
};

int main() {

    int n, m;
    scanf("%d %d\n", &n, &m);

    UnionFind unionFind(n);

    for (int i = 0; i < m; i++) {
        char optiones;
        int a, b;

        scanf("%c %d %d\n", &optiones, &a, &b);

        if (optiones == '?') {
            printf("%s\n", (unionFind.is_same_set(a, b) ? "yes" : "no"));
        } else {
            unionFind.join_set(a, b);
        }
    }

    return 0;
}
