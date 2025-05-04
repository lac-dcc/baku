#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vll vector<ll>
using namespace std;
 
inline void sol() {
  //
  int n;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }
  vector<bool> vis(n + 1, false);
  vector<int> cnt(n + 1, 0);
  function<int(int)> dfs = [&](int u) -> int{
    if(vis[u])
      return cnt[u];
    vis[u] = true;
    for(auto &v: adj[u])
      cnt[u] += dfs(v);
    return cnt[u] + 1;
  };
  dfs(1);
  cout << cnt[1] << " ";
  for(int i = 2; i <= n; i++)
    cout << cnt[i] << " ";
  return;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
 
  sol();
 
  return 0;
}
