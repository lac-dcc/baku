#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 10e5 + 7;
vector<vector<int>> g(maxn);
vector<bool> vi(maxn, false);
vector<int> ans;
int n, m;
 
void bfs(int u)
{
  queue<int> q;
  q.push(u);
  vi[u] = true;
  ans.push_back(u);
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
 
    for (int v : g[t])
    {
      if (!vi[v])
      {
        q.push(v);
        vi[v] = true;
      }
    }
  }
}
 
int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
  for (int i = 1; i <= n; i++)
  {
    if (!vi[i])
    {
      bfs(i);
    }
  }
 
  cout << ans.size() - 1 << endl;
  for (int i = 0; i < ans.size() - 1; i++)
  {
    cout << ans[i] << " " << ans[i + 1] << endl;
  }
 
  return 0;
}
