#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PII;
const ll mx = 1e6+10, mod = 1e9+7;
 
vector<ll>coin;
ll vis[mx];
ll dp[mx];
ll solve(ll n) {
    if(n==0) return 0;
    if(n<0) return INT_MAX;
    if(vis[n]) return dp[n];
    ll ans = INT_MAX;
    for(auto c: coin) {
        ans = min(ans,solve(n-c)+1);
    }
    dp[n] = ans;
    vis[n] = 1;
    return dp[n];
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll p,n;
    cin>>p>>n;
    for(ll i=0, oo; i<p; i++) cin>>oo, coin.push_back(oo);
    ll ans = solve(n);
    if(ans!=INT_MAX)
        cout<<solve(n)<<endl;
    else cout<<-1<<endl;
}
 
 
