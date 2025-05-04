#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
int const N=1e6+1;
int const mod=1e9+7;
int n;
vector<int>v;
vector<ll>dp(N,-1);
 
ll rec(int x){
    if(x<0)
        return 0;
    if(!x)
        return 1;
    if(dp[x]!=-1)
        return dp[x];
    ll cur=0;
    for(int i=0;i<n;i++){
        cur+=rec(x-v[i]);
        cur%=mod;
    }
    return dp[x]=cur;
}
 
void lets_hope_its_right(){
    cin>>n;
    int x; cin>>x;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    cout<<rec(x);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt=1; //cin>>tt;
    while(tt--) lets_hope_its_right();
}