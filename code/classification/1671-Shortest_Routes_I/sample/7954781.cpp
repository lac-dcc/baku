#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
 
  vector<vector<pair<int, ll>>> g(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
 
  // sort by distance, smallest first
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dist(n + 1, LLONG_MAX);
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [ud, u] = pq.top();
    pq.pop();
    if (ud != dist[u]) continue; // if we have found a better path to u after this one being added to the queue
    for (auto& [v, w] : g[u]) {
      ll vd = dist[u] + w;
      if (vd >= dist[v]) continue; // already have a better path for to v
      dist[v] = vd;
      pq.push({vd, v});
    }
  }
  for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}
