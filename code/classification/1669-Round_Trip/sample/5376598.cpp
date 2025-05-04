// it's not about code or how decoratively you write it, it's about mind and what you write, cp is a mind sport
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma")
#include <bits/stdc++.h>
#define debug(...)
#else
#include <algo/debug.h>  
#endif
using namespace std;
 
#define ll                  long long
#define nl                  '\n'
#define pb                  push_back
#define f                   first
#define s                   second
#define vt                  vector
#define vll                 vt<ll> 
#define pb                  push_back
#define vvll                vt<vt<ll>>
#define pll                 pair<ll,ll>
#define vpll                vt<pll>
#define vvpll               vt<vt<pll>>
#define sz(x)               (ll)(x).size()
#define here()              debug(__LINE__)
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define mem0(x)             memset(x,0,sizeof(x))
#define mem1(x)             memset(x,-1,sizeof(x))
#define YES(x)              cout << (x ? "YES" : "NO") << nl;
 
template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }
 
void solve();
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
 
const ll INF64 = 1e18;
const int INF32 = 1e9;
const ll MOD = 1e9+7;
const ll N = 2e5 + 5; 
 
vvll adj;
ll n, m;
vector<bool> vis;
vector<ll> parent;
ll ansNode;
 
bool dfs(ll cur, ll par = -1)
{
    if(vis[cur] == 2)
    {
        return false;
    }
    if(vis[cur] == 1)
    {
        ansNode = cur;
        parent[cur] = par;
        return true;
    }
    vis[cur] = 1;
    parent[cur] = par;
    // debug(cur, par);
    for(auto &child : adj[cur])
    {
        if(child == par)
            continue;
        if(dfs(child, cur))
        {
            return true;
        }
    }
    vis[cur] = 2;
    return false;
}
 
void solve() 
{
    cin >> n >> m;
    vis = vector<bool>(n + 1, false);
    parent = vll(n + 1, -1);
    adj = vvll(n + 1);
    for(int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(dfs(i))
            {
                vll ans;
                int curNode = ansNode;
                // debug(parent, ansNode);
                do
                {
                    ans.push_back(curNode);
                    debug(curNode);
                    curNode = parent[curNode];
                }while(curNode != ansNode);
                ans.push_back(ansNode);
                cout << sz(ans) << nl;
                for(auto x:ans)
                {
                    cout << x << " ";
                }
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}
