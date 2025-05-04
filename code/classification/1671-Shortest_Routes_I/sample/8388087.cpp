#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define endl "\n"
 
int n = 0, m = 0;
 
void Dijkstra_Algo(vector<pair<ll, ll>> *adj, int n, int m) {
    
    vector<ll> minLen(n+1, LONG_LONG_MAX), vis(n+1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
    pq.push({0, 1});
    minLen[1] = 0;
 
    while (!pq.empty()) {
        ll node = pq.top().second;
        ll lenReq = pq.top().first;
        pq.pop();
 
        if(vis[node] == 1) continue;
        vis[node] = 1;
 
        for (auto &child : adj[node]) {
            ll adjNode = child.first;
            ll length = child.second;
 
            if (minLen[adjNode] > (lenReq + length)) {
                minLen[adjNode] = lenReq + length;
                pq.push({lenReq + length, adjNode});
            }
        }
    }
 
    for(int node = 1; node <= n; node++) {
        cout << minLen[node] << " ";
    }
 
}
int main()
{
    fast_cin();
    
    cin >> n >> m;
 
    ll u = 0, v = 0, l = 0;
    vector<pair<ll, ll>> adj[n+1];
    for(int i =0; i < m; i++) {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
    }
 
    Dijkstra_Algo(adj, n, m);
    
    return 0;
}
