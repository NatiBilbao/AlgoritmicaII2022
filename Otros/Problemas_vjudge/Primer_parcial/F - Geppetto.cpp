#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;

int n, m;
int a, b;
set<pair<int,int>> s;
int main(){

    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        if (a > b){
            swap(a,b);
        }
        s.insert(make_pair(a,b));
    }

    int total_valid = 0;
    for (int bm=0; bm<(1<<n); bm++){
        bool valid = true;
        for (auto p: s){
            a = p.first;
            b = p.second;
            bool both_on_pizza = ((bm & (1<<a)) && (bm &(1<<b)) );

            if (both_on_pizza){
                valid = false;
                break;
            }

            if (!valid)break;
        }

        if(valid)total_valid++;
    }

    cout << total_valid << endl;
}