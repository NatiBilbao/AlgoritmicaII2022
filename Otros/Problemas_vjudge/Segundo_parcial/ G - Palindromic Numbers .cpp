#include <iostream>
#include <cstring>
#include <cstdio>

#define ll long long

using namespace std;

int dig[20],ndig[20];

ll dp[20][20][2];

ll sovel(int l,int s,int f,int p){

    if(l==0)return (ll)f;

    if(dp[l][s][f]!=-1 && !p) return dp[l][s][f];

    int t=(p?dig[l]:9);

    ll res=0;

    for(int i=0;i<=t;i++) {

        ndig[l]=i;

        if(!i && l==s)
        {
            res+=sovel(l-1,s-1,f,p && i==t);
        }
        else if(f && l<=(s+1)/2)
        {
            res+=sovel(l-1,s,i==ndig[s-l+1],p && i== t);
        }
        else
        {
            res+=sovel(l-1,s,f,p && i==t);
        }
    }

    if(!p)dp[l][s][f]=res;

    return res;
}

ll sol(ll x) {

    if(x<0) return 0;

    if(x==0) return 1;

    int l=0;

    while(x) {

        dig[++l] = x%10;

        x/=10;
    }

    return sovel(l,l,1,1);
}

int main() {

    int t;

    ll n,m;

    int Case=0;

    scanf("%d",&t);

    memset(dp,-1 ,sizeof(dp));

    while(t--) {

        scanf("%lld%lld",&m,&n);

        if(m<n) swap(m,n);

        printf("Case %d: %lld\n",++Case,sol(m)-sol(n-1));
    }
    return 0;
}