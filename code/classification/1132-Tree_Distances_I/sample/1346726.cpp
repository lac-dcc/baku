#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
typedef long double lxd;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
#define mem(dp, a) memset(dp, a, sizeof dp)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repb(i, a, b) for (ll i = a; i >= b; i--)
#define f(i, n) for (ll i = 0; i < n; i++)
#define fo(i, n, x) for (ll i = x; i <= n; i++)
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define make_graph(a, b) \
    adj[a].pb(b);        \
    adj[b].pb(a);
#define tr(c, it) for (((c).begin())it = (c).begin(); it != (c).end(); it++)
#define test   \
    ll tt;     \
    cin >> tt; \
    label:     \
    while (tt--)
#define fls fflush(stdout)
#define F first
#define S second
#define all(arr) arr.begin(), arr.end()
#define read(arr, n) f(i, n) cin >> arr[i]
#define INT_BITS 32
 
const ll mod = 10007 ;
const ll inf = 1e18 ;
const ll MAXN = 2e5 + 2 ;
 
vector<vll> adj(MAXN) ;
vll ans(MAXN, 0) ;
vll m1(MAXN, 0), m2(MAXN, 0) ;
 
 
ll dfs(ll node, ll p){
    
    for(auto &ch : adj[node]){
        if(ch == p)continue ;
        ll tt = 1ll + dfs(ch, node) ;
        
        if(tt > m1[node])m2[node] = m1[node], m1[node] = tt ;
        
        else if(tt > m2[node])m2[node] = tt ;
        
        ans[node] = max(ans[node], tt) ;
    }
    
    return ans[node] ;
}
 
void dfs1(ll node, ll p, ll maxi){
    
    ans[node] = max(ans[node], maxi) ;
    
    for(auto &ch : adj[node]){
        if(ch == p)continue ;
        if(1 + ans[ch] == m1[node]){
            dfs1(ch, node, max(1 + maxi, 1 + m2[node])) ;
        }
        else dfs1(ch, node, max(1 + maxi, 1 + m1[node])) ;
    }
}
 
int main(){
    ll n ;
    cin >> n ;
    
    ll u , v ;
    
    f(i,n - 1){
        cin >> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    
     dfs(1, 0) ;
     dfs1(1, 0, 0) ;
     
     fo(i,n,1)cout << ans[i] << " " ;
     return 0;
}
