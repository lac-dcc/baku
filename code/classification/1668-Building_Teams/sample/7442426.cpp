#include <bits/stdc++.h>
using namespace std;
 
vector<int> edges[200001];
int paint[100001];
bool impossible = 0;
 
void dfs(int node, int p) {
  if (paint[node])
    return;
  paint[node] = p;
  int np = (p == 1) ? 2 : 1;
  for (int child : edges[node]) {
    if (paint[child] == p) {
      impossible = 1;
      return;
    }
    if (paint[child] == 0) {
      dfs(child, np);
    };
  }
}
 
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  bool possible = 1;
  for (int i = 1; i <= n; ++i) {
    dfs(i, 1);
  }
  if (!impossible) {
    for (int i = 1; i <= n; ++i) {
      cout << paint[i] << " ";
    }
  } else {
    cout << "IMPOSSIBLE"
         << "\n";
  }
}