#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<vector<int> > adj;
vector<int> dist1;
vector<int> dist2;
 
void dijkstra(int start, vector<int> &dist) {
    priority_queue<pair<int, int> > q;
    q.push({0, start});
    dist[start] = 0;
 
    while(!q.empty()) {
        int u = q.top().second; q.pop();
 
        for (auto v : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u]+1;
            q.push({-dist[v], v});
        }
    }
}
 
int main()
{
    cin.tie(0);
 
    cin >> n;
 
    adj.resize(n);
    dist1.resize(n, -1);
    dist2.resize(n, -1);
 
    for (int i = 0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dijkstra(0, dist1);
 
    pair<int, int> mx = {0, 0};
    for (int i = 0; i<n; i++) {
        if (dist1[i] > mx.second) {
            mx.first = i;
            mx.second = dist1[i];
        }
    }
 
    dist1.assign(n, -1);
    dijkstra(mx.first, dist1);
 
    mx = {0, 0};
    for (int i = 0; i<n; i++) {
        if (dist1[i] > mx.second) {
            mx.first = i;
            mx.second = dist1[i];
        }
    }
 
    dijkstra(mx.first, dist2);
 
    for (int i = 0; i<n; i++) cout << max(dist1[i], dist2[i]) << ' ';
 
    return 0;
}
