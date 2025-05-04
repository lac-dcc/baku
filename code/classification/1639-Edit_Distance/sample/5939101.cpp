#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
 
void solve(){
 
    string s,t;
    cin>>s>>t;
 
    ll n = s.size(),m = t.size();
    ll dp[n+1][m+1];
 
    for(ll i=0;i<=n;i++) dp[i][0] = i;
    for(ll i=0;i<=m;i++) dp[0][i] = i;
 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
            }
        }
    }
 
    cout<<dp[n][m]<<'\n';
 
 
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
 
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
    return 0;
}