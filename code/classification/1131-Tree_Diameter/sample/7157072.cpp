#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
 
using ll  = long long;
using ld  = long double;
using vl = vector<ll>;
using vpl = vector<pair<ll,ll>>;
 
#define all(x)    x.begin(), x.end()
#define For(i,n)   for(ll i = 0; i < n; ++i)
#define inpt(v) For(i,(ll)v.size()) cin >> v[i];
#define print(v)  for(auto it : v) cout << it << " "; cout << "\n";
#define ya      cout<<"YES\n";
#define na      cout << "NO\n";
#define nl      cout<< "\n";
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)
 
const int M = 1e9+7; 
const int N = 2e5+10;
 
ll n, a, b, c, k, m, x, y, q;
 
vl depth;
vector<vl> adj;
 
void dfs(ll node, ll par)
{   
    if(par!=-1) depth[node] = depth[par] + 1;
    for(auto it : adj[node])
    {
        if(it==par) continue;
        dfs(it,node);
    }
}
 
void solve()
{
    cin>>n;
 
    adj.assign(n+1,vl());
    depth.assign(n+1,0);
 
    For(i,n-1)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    dfs(1,-1);
    ll mx = Vmax(depth),root;
    for(ll i=1; i<=n; i++)
    {
        if(depth[i]==mx) root=i;
        depth[i]=0;
    }
 
    dfs(root,-1);
    mx = Vmax(depth);
    cout<<mx<<endl;
    
}
 
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
int t = 1;
// cin >> t;
while(t--) solve();
return 0;
}
