#include<bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define INF 1000000000
#define ll long long int
 
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<int>coin(n);
    for(ll i =0;i<n;i++)cin>>coin[i];
    ll dp[x+1];
    dp[0]=0;
    for(ll i=1;i<=x;i++)dp[i]=INF;
    for(ll j=1;j<=x;j++){
        for(ll i=1;i<=n;i++){
            if(coin[i-1]<=j){
                ll ans = dp[j-coin[i-1]];
                if(ans!=INF) dp[j]=min(dp[j],1+ans);
            }
        }
    }
    if(dp[x]==INF)cout<<"-1";
    else cout<<dp[x];
}
 
 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
}
