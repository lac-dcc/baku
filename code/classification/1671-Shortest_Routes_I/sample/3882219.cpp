#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long int;
using pli = pair<ll,int>;
const int mxn = 1e5 + 10;
vector<pli> adj[mxn];
 
const ll inf = 1e14 + 7;
bool flag[mxn];
 
int main () {
    ios::sync_with_stdio(false); cin.tie(0);
//    freopen("dijk_input.txt", "r", stdin);
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
//        adj[v].push_back({u,w});
    }
 
    priority_queue<pli, vector<pli>, greater<pli>> pq; //dist, node
    vector<ll> dist(n+1, inf);
    dist[1] = 0;
    pq.push({dist[1], 1});
    while(!pq.empty()) {
        ll d,u; tie(d,u) = pq.top(); pq.pop();
        if(flag[u]) continue;
        flag[u] = true;
        for(auto vw : adj[u]) {
            int v,w; tie(v,w) = vw;
            if(flag[v]) continue;
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}
