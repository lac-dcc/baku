#include <bits/stdc++.h>
 
using namespace std;
 
long long MX = 2e18;
 
int main()
{
    long long n, m;
    cin >> n >> m;
 
    vector<vector<pair<long long, long long> > > adj(n);
    vector<bool> visited(n, false);
    vector<long long> dist(n, MX);
 
    for (long long i = 0; i<m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
 
        adj[a].push_back(make_pair(b, c));
    }
 
    priority_queue<pair<long long, long long> > q;
    q.push(make_pair(0, 0));
    dist[0] = 0;
 
    while(!q.empty()) {
        long long u = q.top().second; q.pop();
 
        if (visited[u] == true) continue;
        visited[u] = true;
 
        for (auto p : adj[u]) {
            long long v = p.first, d = p.second;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u]+d;
                q.push(make_pair(-dist[v], v));
            } else continue;
        }
    }
 
    for (long long i = 0; i<n; i++) cout << dist[i] << ' ';
    return 0;
}