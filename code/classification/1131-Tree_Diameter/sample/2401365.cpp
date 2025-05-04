#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define fo(i, x, y)   for (__typeof(x) i = x; i < y; ++i)
#define fr(i, x, y)   for (__typeof(x) i = x; i > y; i--)
#define F first
#define S second
#define vdp(n,x) vector<vector<ll>>dp(n+1,vector<ll>(x+1));
#define ms(a,x) memset(a, x, sizeof(a))
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
const ll mod=1000000007;
const ll AM=2e5+5;
using namespace std;
 
vector<ll>adj[AM];
vector<ll>dp(AM+1, 0), vis(AM+1, 0);
ll ans=1;
 
ll dfs(ll i){
    vis[i]=1;
    if(adj[i].size()==1 && vis[adj[i][0]]){
        return 1;
    }
    for(ll u: adj[i]){
        if(!vis[u]){
            dp[u]=dfs(u);
            ans=max(ans, dp[i]+dp[u]);
            dp[i]=max(dp[i], dp[u]+1);
        }
    }
    return dp[i];
}
 
int main()
{
    fast;
    ll n; cin>>n;
    fo(i,0,n-1){
        ll x,y; cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0);
    fo(i,0,n){
        ans=max(ans,dp[i]);
    }
    cout<<ans-1;
}
