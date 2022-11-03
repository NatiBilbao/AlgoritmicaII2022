#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    for(int i=1; i<=test; i++){
        int n, temp;
        cin>>n;
        int m[n+1];
        m[0]=0;
        for(int j=1; j<=n; j++){
            cin>>m[j];
        }
        temp =0;
        for(int j=1; j<=n; j++){
            if((m[j]-m[j-1])>temp){
                temp = m[j]-m[j-1];
            }
        }
        int ans;
        ans = temp;

        for(int j=1; j<=n; j++){
            if((m[j]-m[j-1])==temp){
                temp--;
            }
            else if((m[j]-m[j-1])>temp)
            {
                ans++;
                break;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
