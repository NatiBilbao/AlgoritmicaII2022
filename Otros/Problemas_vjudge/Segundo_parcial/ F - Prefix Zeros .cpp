#include <bits/stdc++.h>
using namespace std;

#define ll long long int


ll sol(ll m, string s){
    ll agr = 0;
    for(int i=m;i>=0;i--){
        ll c = (int(s[i])-int('0')+agr)%10;
        if(c==0)
            continue;
        agr+=10-c;
    }
    return agr;
}

int main(){
    int b;
    cin>>b;
    while(b--){
        ll n,k;
        cin >> n >> k;
        string st;
        cin >> st;
        ll l=0,r=n-1,res=0;
        while(l<=r){
            ll m=(l+r)/2;
            if(sol(m,st)>k)
                r=m-1;

            else{
                res = m+1;
                l=m+1;
            }
        }
        cout<<res<<endl;
    }
}
