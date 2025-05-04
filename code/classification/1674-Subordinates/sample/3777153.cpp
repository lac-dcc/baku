#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define inp(a, n)           \
    for (ll j = 0; j < n; j++) \
        cin >> a[j];
#define lp(i, t, n) for (ll i = t; i < n; i++)
#define alp(i, a) for (auto i : a)
#define rev(i, t, n) for (ll i = t; i >= n; i--)
 
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define nl "\n"
#define sz(a) long long((a).size())
#define all(c) c.begin(),c.end()
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define ii pair<ll,ll>
#define vii vector<pair<ll,ll>>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define mp make_pair
#define vbool vector<bool>
#define mod 1000000007
#define mod1 998244353
#define ff first
#define ss second
#define test  \
    ll t;    \
    cin >> t; \
    while (t--)
#define MAX (ll) 1e18
#define MIN (ll) -1e18
using namespace std;
 
ll dfs(ll node, vvll &adj, vll &dp){
    if(dp[node] != -1) return dp[node];
 
    ll ans = 0;
    alp( i , adj[node]){
        ans += 1 + dfs(i, adj, dp);
    }
    return dp[node] = ans;
}
 
void solve(){
    ll n;
    cin>>n;
    vvll adj(n+1);
    lp( i , 2,  n+1){
        ll u;
        cin>>u;
        adj[u].pb(i);
    }
    vll dp(n+1, -1);
    dfs(1, adj, dp);
    lp(i, 1, n+1){
        cout<<dp[i]<<" ";
    }
}
 
int main(){
    IOS
    // test
    solve();
}
