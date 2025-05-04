#include<bits/stdc++.h>
#define int long long 
using namespace std;
 
const int inf = 1e14;
int n, m;
vector< vector<pair<int,int>> > adj, revAdj;
 
void helper(int src, vector<int> &dist, vector<vector<pair<int,int>>> &adj) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        vector<int> p = pq.top();
        pq.pop();
        int d = p[0], node = p[1];
        if(dist[node] != d) continue;
        for(pair<int,int> p : adj[node]) {
            int neigh = p.first, distance = p.second;
            if(dist[neigh] > d+distance) {
                dist[neigh] = d+distance;
                pq.push({dist[neigh], neigh});
            }
        } 
    }
}
 
int32_t main() {
    cin>>n>>m;
    adj.assign(n + 1, vector<pair<int, int>>());
    revAdj.assign(n + 1, vector<pair<int, int>>());
 
    for(int i=1; i<=m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        revAdj[b].push_back({a, c});
    }
 
    vector<int> dist1(n+1, inf), distn(n+1, inf);
    helper(1, dist1, adj);
    helper(n, distn, revAdj);
 
    int ans = 1e14;
    for(int i=1; i<=n; i++) {
        for(pair<int,int> p : adj[i]) {
            int to = p.first, weight = p.second;
            int local = dist1[i] + weight/2 + distn[to];
            ans = min(ans, local);
        }
    }
    cout<<ans<<"\n";
}
