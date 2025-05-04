#include <bits/stdc++.h>
using namespace std;
 
#define setup() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
#define printV(v) for (int i = 0; i < v.size() - 1; i++) cout << v[i] << ' '; cout << v.back() << endl;
 
signed main() {
  setup();
 
  int n, m;
  cin >> n >> m;
 
  vector<list<int>> graph(n + 1);
  for (int i = 0, s, t; i < m; i++) {
    cin >> s >> t;
    graph[s].push_back(t);
    graph[t].push_back(s);
  }
 
  // DFS
  vector<int> visit_time(n + 1), parent(n + 1);
  for (int i = 1; i <= n; i++) if (!visit_time[i]) {
    stack<int> nodes({ i });
    while (!nodes.empty()) {
      int node = nodes.top(); nodes.pop();
      visit_time[node] = visit_time[parent[node]] + 1;
 
      for (auto& adj : graph[node]) {
        if (!visit_time[adj]) {
          parent[adj] = node;
          nodes.push(adj);
        } else if (visit_time[node] - visit_time[adj] >= 2) {
          vector<int> path = { adj };
 
          while (node != adj) {
            path.push_back(node);
            node = parent[node];
          }
 
          path.push_back(adj);
 
          cout << path.size() << endl;
          printV(path);
 
          return 0;
        }
      }
    }
  }
 
  cout << "IMPOSSIBLE\n";
}
