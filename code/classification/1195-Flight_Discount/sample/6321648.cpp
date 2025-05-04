#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define vvi vector<vector<ll> >
#define vi vector<ll>
#define pb(x) push_back(x)
ll n, E;
 
vi dijikstra(vector<vector<pii> >& adj, int st){
    vi dist(n+1, LLONG_MAX);
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, st));
    while(!pq.empty()){
        ll u = pq.top().S, d = pq.top().F;
        pq.pop();
        if(dist[u] < d) continue;
        for(auto e : adj[u]){
            ll v = e.F, c = e.S;
            if(dist[v] > d + c){
                dist[v] = d+c;
                pq.push(pii(dist[v], v));
            }
        }
    }
    return dist;
}
 
int main(){
    cin >> n >> E;
    vector<vector<pii> > adj(n+1);
    vector<vector<pii> > rev_adj(n+1);
    for(ll i = 0; i < E; i++){
        ll a, b, c;
        cin >> a >> b >> c; 
        adj[a].push_back(pii(b, c));
        rev_adj[b].push_back(pii(a, c));
    }
    vi dist1 = dijikstra(adj, 1);
    vi distN = dijikstra(rev_adj, n);
    ll ans = LLONG_MAX;
    // for(auto x : dist1) cout << x << " ";
    // cout << "\n";
    // for(auto x : distN) cout << x << " ";
    // cout << "\n";
    for(int u = 1; u <= n; u++){
        for(auto e : adj[u]){
            int v = e.F, w = e.S;
            if(dist1[u] != LLONG_MAX && distN[v] != LLONG_MAX) ans = min(ans, dist1[u] + w/2 + distN[v]);
        }
    }
    cout << ans << "\n";
}
