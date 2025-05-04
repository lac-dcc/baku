#include<bits/stdc++.h>
using namespace std ;
 
#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define sz(a)           (ll)a.size()
#define FOR(a,b,c)      for(int(a) = (b); (a) < (c); ++(a))
#define FORN(a,b,c)     for(int(a) = (b); (a) <= (c); ++(a))
#define FORD(a,b,c)     for(int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a,b,c)    for(int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a,b,c)     for(char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a,b)    for(auto&(a) : (b))
#define rep(i,n)        FOR(i,0,n)
#define repn(i,n)       FORN(i,1,n)
#define SQR(x)          ((LL)(x) * (x))
#define RESET(a,b)      memset(a, b, sizeof(a))
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double
#define endl            '\n'
#define mod             1000000007 
 
 
template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }
 
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} 
 
 
void dfs(vector<vector<int>>& adj, int y, vector<bool>& vis)
{
    vis[y] = true;
 
    for(auto x : adj[y])
    {
        if(!vis[x])
        {
            dfs(adj, x, vis);
        }
    }
    return ; 
} 
 
void Siuuu()
{ 
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n, false);
 
    vector<int> ans;
 
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
            dfs(adj, i, vis);
        }
    }
    int k = ans.size()-1;
    cout<<k<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    
    int TESTS = 1;
    // cin >> TESTS;
    while(TESTS--) 
        Siuuu();
    return 0;
}
