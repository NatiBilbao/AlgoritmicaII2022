#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll suma(ll x){
    return (x*(x+1))/2;
}

ll bs(ll x){
    ll inicio=1, final=x, mid;
    while(inicio<=final){
        mid=(inicio+final)/2;
        ll check=suma(mid);
        if(check==x || (check<x && suma(mid+1)>x)){
            return mid;
        }else if(check>x){
            final=mid-1;
        }else{
            inicio=mid+1;
        }
    }
    return mid;
}

int main(){
    ll n;
    cin>>n;
    while(n--){
        ll x;
        cin>>x;
        ll in=bs(x);
        cout<<in<<endl;
    }
    return 0;
}