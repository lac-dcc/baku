#include "bits/stdc++.h"
using namespace std;
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m; cin >> n >> m;
  
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v); 
    g[v].push_back(u);
  }
  
  vector<int> parent(n + 1); 
  
  vector<int> res;
  function<void(int)> printPath = [&](int x) {
    if (parent[x] == -1) {
      res.push_back(x); 
      reverse(res.begin(), res.end());
      cout << (int)res.size() << "\n";
      for (auto &v: res) {
        cout << v << " \n"[&v == &res.back()];
      }
      exit(false);
    }
 
    res.push_back(x);
    printPath(parent[x]);
  };
 
  queue<int> q;
  q.push(1); parent[1] = -1; 
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (x == n) printPath(n);
    for (auto &y: g[x]) {
      if (parent[y]) continue;
      parent[y] = x; q.push(y);
    }
  }
 
  cout << "IMPOSSIBLE\n";
 
}
