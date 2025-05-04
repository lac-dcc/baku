#include<bits/stdc++.h>
#include<climits>
using namespace std;
#define pii pair<int,int>
#define int long long int
vector<int> dis(2501, 1e18);
vector<int> par(2501, -1);
int findCycle(int s, vector<vector<int>> &e, int n) {
  dis[s] = 0;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (auto edg : e) {
      int u = edg[0], v = edg[1], wt = edg[2];
      if (dis[u] + wt < dis[v]) {
        dis[v] = dis[u] + wt;
        par[v] = u;
        if (i == n - 1) {
          ans = v;
        }
      }
    }
    // for (int i = 1; i <= n; i++)
    // cout << dis[i] << " ";
    // cout << "\n";
  }
 
  return ans;
}
void solve() {
  int n, m; cin >> n >> m;
  vector <int> dist(n + 1, 1e18);
  vector<vector<int>> e(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    cin >> e[i][0] >> e[i][1] >> e[i][2];
  }
  int x;
  for (int s = 1; s <= 1; s++) {
    if (dis[s] == 1e18)
    {
      x = findCycle(s, e, n);
      if (x != -1)  break;
    }
  }
  if (x == -1) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++)
    x = par[x];
  int temp = x;
  int p = par[x];
  deque<int> ans;
  while (p != temp) {
    ans.push_front(x);
    x = p;
    p = par[p];
  }
  ans.push_front(x);
  ans.push_back(x);
  cout << "YES\n";
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
 
  int t ;
  t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
