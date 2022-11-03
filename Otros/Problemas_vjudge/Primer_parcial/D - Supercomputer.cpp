#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

class SuperComp {
public:
    SuperComp(int n) {
        ft.assign(n, 0);
        vv.assign(n, 0);
    }

    int rqs(int j) {
        int sum = 0;

        while (j >= 0) {
            sum += ft[j];
            j = (j & j + 1) - 1;
        }

        return sum;
    }

    int rqs(int i, int j) {
        return rqs(j) - rqs(i);
    }

    void update(int j, int v) {
        vv[j] += v;
        while (j < ft.size()) {
            ft[j] += v;
            j |= (j + 1);
        }
    }

    int get(int i) {
        return vv[i];
    }

private:
    vector<int> ft;
    vector<int> vv;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    SuperComp superComp(n + 1);

    char op;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 'F') {
            cin >> a;
            if (superComp.get(a)) {
                superComp.update(a, -1);
            } else {
                superComp.update(a, +1);
            }
        } else {
            cin >> a >> b;
            cout << superComp.rqs(a - 1, b) << endl;
        }
    }

    return 0;
}
