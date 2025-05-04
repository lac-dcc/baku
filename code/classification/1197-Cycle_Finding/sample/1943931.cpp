#include<bits/stdc++.h>
 
using namespace std;
#define int int64_t
 
struct Edge {
  int u, v, c;
};
 
int n, m;
vector<Edge> e;
const int inf = 1e18;
 
signed main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    e.push_back({u, v, w});
  }
  vector<int> dis(n);
  vector<int> par(n , -1);
  int change = -1;
  for (int i = 0; i < n; i++) {
    change = -1;
    for (auto E : e) {
      if (dis[E.u] + E.c < dis[E.v]) {
        dis[E.v] = dis[E.u] + E.c;
        par[E.v] = E.u;
        change = E.v;
      }
    }
  }
  if (change == -1) {
    cout << "NO" << '\n';
  } else {
    for (int i = 0; i < n; i++)
      change = par[change];
    vector<int> cycle;
    for (int v = change;;v = par[v]) {
      cycle.push_back(v);
      if (v == change and cycle.size() > 1) {
        break;
      }
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << '\n';
    for (int v : cycle) {
      cout << v + 1 <<  ' ';
    } 
    cout << '\n';
  }
  return 0;
} //Hajimemashite
 
