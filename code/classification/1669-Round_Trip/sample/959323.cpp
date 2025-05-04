#pragma GCC optimize("Ofast")
#pragma GCC target("fma")
 
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
#define f(i, a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define vi vector<ll>
#define pii pair<ll, ll>
#define all(p) p.begin(), p.end()
#define nl cout << "\n"
#define mii map<ll, ll>
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
 
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MAX = 1e6;
bool flag = 0;
ll n, m;
vi adj[MAX];
ll p[MAX] = {0};
vi v;
ll vis[MAX] = {0};
 
 
void dfs(ll curr, ll prev)
{
    if(vis[curr]) return;
    p[curr] = prev;
   
    vis[curr] = 1;
    for (auto u : adj[curr])
    {
        if (u == prev)
            continue;
        if (vis[u])
        {
            v.pb(curr);
            ll curr_ = curr;
            while (u ^ curr_)
            {
                curr_ = p[curr_];
                v.pb(curr_);
            }
            v.pb(curr);
 
            cout << v.size();
            nl;
            f(j, 0, v.size()-1) { cout << v[j] << " "; }
            exit(0);
        }
        dfs(u, curr);
    }
}
 
void solve()
{
 
    cin >> n >> m;
    
    f(i, 0, m - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    f(i, 1, n)
    {
       
        if(vis[i])
            continue;
        dfs(i,-1);
    }
    cout<<"IMPOSSIBLE";
}
 
int main()
{
    fastio;
    
    ll tc = 1;
    
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
 
    return 0;
}
