#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    int a, b;

    while (cin >> a >> b) {

        set<pair<int, int>> s;

        int x, y;
        for (int i = 0; i < b; i++) {
            cin >> x >> y;
            s.insert({max(x, y) - 1, min(x, y) - 1});
        }

        int p = 1;
        for (int i = 0; i < a; i++) p *= 2;

        int res = 0;

        for (int i = 0; i < p; i++) {
            bool bn = true;

            for (auto ss : s) {
                if (i & (int)pow(2, ss.first) && i & (int)pow(2, ss.second)) {
                    bn = false;
                    break;
                }
            }

            if (bn) {
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}