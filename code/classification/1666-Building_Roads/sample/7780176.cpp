#include <bits/stdc++.h>
using namespace std;
 
/* echoSTROMLOS */
 
#define el '\n'
#define fi first
#define se second
#define ll long long
#define pb push_back
typedef vector<ll> vl;
#define eb emplace_back
inline void readINFile();
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
//#define max(a, b) a>b ? a:b
//#define min(a, b) a<b ? a:b
typedef vector<bool> v_bool;
typedef unsigned long long ull;
typedef vector<pair<ll,ll>> vpl;
#define all(v) v.begin(), v.end()
#define maxHeap priority_queue<ll>
typedef unordered_map<ll, ll> uml2l;
typedef unordered_map<char, ll> umc2l;
#define mx3(a, b, c)  max(a, max(b, c))
#define mn3(a, b, c)  min(a, min(b, c))
#define minHeap priority_queue<ll, vl, greater<ll>>
#define fastIO_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
inline void printV(vl &a) { for (auto o: a) cout<<o<<" "; cout<<"\n"; }
#define fp fixed << setprecision(12)
 
inline void dfs(int node, vector<vl>& adj, v_bool& visited) 
{
    visited[node] = true;
    for (auto v: adj[node]) {
        if (!visited[v]){
            dfs(v, adj, visited);
        }
    }
 
 
} 
 
inline void solve()
{
    ll n, m; cin>>n>>m;
    vector<vl> adj(n+1);
    v_bool visited(n+1, false);
    for (int i=1; i<=m; i++) {
        ll a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vl ans;
    for (ll i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i,adj,visited);
            ans.pb(i);
        }
    }
    ll lenmna = ans.size()-1;
    cout<<lenmna<<el;
    for (ll i=0; i<lenmna; i++) {
        cout<<ans[i]<<" "<<ans[i+1]<<el;
    }
    
}
int main()
{
    fastIO_
    //readINFile();
    ll tc=1;// cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
