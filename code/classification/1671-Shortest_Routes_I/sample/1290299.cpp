#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<long long> dist(n + 1, LONG_LONG_MAX);
    dist[1] = 0LL;
 
    vector<pair<long long, long long>> adj[n + 1];
 
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
 
        adj[a].push_back({b, c});
    }
 
    set<pair<long long, long long>> q;
    q.insert({0LL, 1LL});
 
    while (!q.empty()) {
        long long lowest = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[lowest]) {
            long long node = edge.first;
            long long length = edge.second;
 
            if (dist[lowest] + length < dist[node]) {
                q.erase({dist[node], node});
                dist[node] = dist[lowest] + length;
                q.insert({dist[node], node});
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
 
    cout << "\n";
 
    return 0;
}
