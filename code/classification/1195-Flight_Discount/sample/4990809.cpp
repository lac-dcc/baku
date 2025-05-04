#include<bits/stdc++.h>
 
#define int int64_t
 
using namespace std;
 
const int MX = 1e5 + 5;
const int INF = LLONG_MAX/3;
 
vector<vector<pair<int, int>>> G, GT;
int cost[MX];
 
 
int V, A;
 
void dijkstra(int s, vector<int> &d, vector<vector<pair<int, int>>> &adj) {
 
    priority_queue<pair<int,int>> q;
 
    for (int i = 1; i <= V; i++)
        d[i] = INF;
    
    d[s] = 0;
    q.push({0, s});
    
    vector<bool> processed(V+1, 0);
    
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
 
        if (processed[a]) continue;
        processed[a] = true;
 
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (d[a] + w < d[b]) {
                
                d[b] = d[a] + w;
                q.push({-d[b], b});
 
                cost[b] = w;
            }
        }
    }
    
}
 
 
signed main() {
 
    cin >> V >> A;
 
    G.assign(V+1, vector<pair<int, int>>());
    GT.assign(V+1, vector<pair<int, int>>());
    vector<array<int, 3>> edges;
    for (int i = 0; i < A; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({from, to, cost});
        G[from].push_back({to, cost});
        GT[to].push_back({from, cost});
    }
 
    vector<int> s_distance(V+1, 0), t_distance(V+1, 0);
 
    dijkstra(V, t_distance, GT);
    dijkstra(1, s_distance, G);
 
    int mn = INF;
    for (int i = 0; i < edges.size(); i++) {
        /*
        cout << "Distancia a " << i << " -> " << s_distance[i] << endl;
        cout << "Distancia a " << i << " -> " << t_distance[i] << endl;
        cout << "Relacion minima a " << i << " -> " << min_dist[i] << endl;
        cout << " ================= " << endl;
        */
 
        mn = min(mn, s_distance[edges[i][0]] + t_distance[edges[i][1]] + edges[i][2]/2);
    }
 
    cout << mn << endl;
 
    return 0;
}
