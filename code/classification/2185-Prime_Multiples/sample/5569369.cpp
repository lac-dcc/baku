#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll A[25];
ll mul(ll n, ll k){
    ll ans=0,t,c;
    for(int i=1;i<(1<<k);i++){
        t=n, c=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                t/=A[j];
                c++;
            }
        }
        if(c&1) ans+=t;
        else ans-=t;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++) cin>>A[i];
    cout<<mul(n, k);
}