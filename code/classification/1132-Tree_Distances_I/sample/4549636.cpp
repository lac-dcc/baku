#include <bits/stdc++.h>
using namespace std;
 
#ifdef AQIB_DEBUG
#include "/debug.h"
#else
#define dbg(...)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> f(n);
  vector<int> ans(n);
  function<void(int, int)> dfs = [&](int cur, int par) {
    f[cur] = 1;
    for (int j : g[cur]) {
      if (j == par)
        continue;
      dfs(j, cur);
      f[cur] = max(f[cur], 1 + f[j]);
    }
  };
  dfs(0, -1);
  function<void(int, int, int)> nfs = [&](int cur, int par, int best) {
    multiset<int> ms;
    for (int j : g[cur]) {
      if (j != par) {
        ms.insert(f[j] + 2);
      }
    }
    for (int j : g[cur]) {
      if (j != par) {
        ms.erase(ms.find(f[j] + 2));
        ans[j] = max(ans[j], ms.empty() ? best + 1 : max(*prev(ms.end()), best + 1));
        nfs(j, cur, ans[j]);
        ms.insert(f[j] + 2);
      }
    }
    ans[cur] = max(ans[cur], best);
  };
  nfs(0, -1, 1);
  dbg(f);
  for (int i = 0; i < n; i++) {
    cout << max(f[i], ans[i]) - 1 << " \n"[i == n - 1];
  }
}
