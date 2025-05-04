#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
signed main() {
    IOS;
    int64_t n,m; cin>>n>>m;
    vector<pair<int64_t,int64_t>>adj[n], rev[n];
    for(int i = 0 ; i < m ; i++) {
        int64_t a,b,c; cin>>a>>b>>c;
        a--,b--;
        adj[a].emplace_back(b,c);
        rev[b].emplace_back(a,c);
    }
    priority_queue<pair<int64_t,pair<int,int>>>pq;
    vector<int64_t>dist[2];
    dist[0].resize(n,1e17);
    dist[1].resize(n,1e17);
    dist[0][0] = dist[1][0] = 0;
    pq.push({0,{0,0}});
    pq.push({0,{0,1}});
    while(!pq.empty()) {
        int node = pq.top().second.first;
        int type = pq.top().second.second;
        int64_t w = -pq.top().first;
        pq.pop();
        if(w != dist[type][node])
            continue;
        for(auto z : adj[node]) {
            if(type == 0) {
                if(dist[0][node] + z.second/2 < dist[1][z.first]) {
                    dist[1][z.first] = dist[0][node] + z.second/2;
                    pq.push({-dist[1][z.first], {z.first,1}});
                }
            }
            if(dist[type][node] + z.second < dist[type][z.first]) {
                dist[type][z.first] = dist[type][node] + z.second;
                pq.push({-dist[type][z.first], {z.first,type}});
            }
        }
    }
    cout << dist[1][n-1];
    return 0;
}
