#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
using vs = vector<string>;
using pll = pair<long long, long long>;
#define endl '\n' 
 
ll mod  = 1e9+7;
ll M = 1e9+7;
ll INF = 1e14;
vector<ll> d;
vector<int> path;
 
void dijk(int n, int m, vector<pll> adj[]){
    d.resize(n+1, INF);
    path.resize(n+1, -1);
    // ll s;  cin >>s;
    ll s = 1;
    d[s] = 0;
 
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
 
    while(!pq.empty()){
        ll a = pq.top().first;
        ll b = pq.top().second;
 
        pq.pop();
        if(d[b] != a){
            continue;
        }
 
        for(auto x: adj[b]){
            ll v = x.first;
            ll w = x.second;
 
            if(d[b] + w < d[v]){
                d[v] = d[b] + w;
                path[v] = b;
                pq.push({d[v], v});
            }
        } 
    }
    for(int i=1; i<=n; i++){
        cout<<d[i]<<" ";
    }cout<<endl;
}
 
void solve(ll &it) {
    ll n, m; cin >>n >>m;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin >>a >>b >>c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
    }
 
    dijk(n,m,adj);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif //ONLINE_JUDGE
    ll x = 1;
    // ll t; cin >>t; while(t--)
    solve(x);
}
