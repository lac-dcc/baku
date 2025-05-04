#include <bits/stdc++.h>
#define fastio fastioread()
#define int long long
const int mod = 1e9 + 7;
using namespace std;
 
void fastioread()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
#ifndef CPH
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
#endif
}
int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> bfs(int u)
{
  vector<int> dist(n + 1, 0);
  queue<int> q;
  q.push(u);
  vis[u] = true;
  dist[u] = 0;
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for (auto v : g[u])
    {
      if (!vis[v])
      {
        q.push(v);
        vis[v] = true;
        dist[v] = dist[u] + 1;
      }
    }
  }
  return dist;
}
void input()
{
  cin >> n;
  g = vector<vector<int>>(n + 1);
  vis = vector<int>(n + 1, 0);
  int u, v;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
int32_t main()
{
  fastio;
  input();
  int u, v;
  vector<int> tmp = bfs(1);
  u = max_element(tmp.begin(), tmp.end()) - tmp.begin();
  vis = vector<int>(n + 1, 0);
  vector<int> dist = bfs(u);
  v = max_element(dist.begin(), dist.end()) - dist.begin();
  cout << dist[v] << endl;
}
