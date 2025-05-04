#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
 
int main() {
  ll n, m, a, b, c;
  cin >> n >> m;
  vector<vector<pii>> adj(n + 1);
  vector<ll> dist(n + 1);
  vector<bool> visited(n + 1,false);
  fill(dist.begin(), dist.end(), LONG_MAX);
  dist[1] = 0;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  priority_queue<pii> q;
  q.push({0, 1});
  while (!q.empty()) {
     a = q.top().second;
    q.pop();
    if (visited[a]) {
      continue;
    }
    visited[a] = true;
    for (pii u : adj[a]) {
      b = u.first;
      c = u.second;
      if (dist[a]+c < dist[b]) {
        dist[b] = dist[a] + c;
        q.push({-1*dist[b], b});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  return 0;
}
