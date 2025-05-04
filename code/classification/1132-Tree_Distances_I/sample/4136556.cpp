#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1e9 + 7;
 
void makedg(int i, vector<vector<int>> &g, vector<vector<int>> &dg, vector<int> &av)
{
  av[i] = 1;
  for (auto it : g[i])
  {
    if (av[it])
      continue;
 
    dg[i].push_back(it);
 
    makedg(it, g, dg, av);
  }
}
 
int dfs1(int i, vector<vector<int>> &dg, vector<vector<pair<int, int>>> &dp)
{
 
  int mx = 0;
 
  for (auto it : dg[i])
  {
    int dis = dfs1(it, dg, dp) + 1;
 
    mx = max(dis, mx);
 
    dp[i].push_back({it, dis});
  }
 
  return mx;
}
 
void dfs2(int i, vector<vector<int>> &dg, vector<vector<pair<int, int>>> &dp, vector<int> &ans)
{
 
  for (auto it : dp[i])
    ans[i] = max(ans[i], it.second);
 
  int mx1 = 0, mx2 = 0;
 
  int it1 = 0, it2 = 0;
 
  for (auto it : dp[i])
  {
    if (it.second > min(mx1, mx2))
    {
      if (mx1 < mx2)
      {
        mx1 = it.second;
        it1 = it.first;
      }
      else{
        mx2 = it.second;
        it2 = it.first;
      }
    }
  }
 
  for (auto it : dg[i])
  {
     if(mx1>mx2)
     {
 
      
      if(it1!=it) dp[it].push_back({i,mx1+1});
      else dp[it].push_back({i,mx2+1});
 
      
     }
     else{
      if(it2!=it) dp[it].push_back({i,mx2+1});
      else dp[it].push_back({i,mx1+1});
     }
 
     dfs2(it,dg,dp,ans);
  }
}
 
void solve()
{
 
  int n;
  cin >> n;
 
  vector<vector<int>> g(n + 1);
  vector<vector<int>> dg(n + 1);
 
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
 
    g[x].push_back(y);
    g[y].push_back(x);
  }
 
  vector<int> av(n + 1);
 
  vector<vector<pair<int, int>>> dp(n + 1);
 
  dp[0].push_back({0, 0});
 
  makedg(1, g, dg, av);
 
  dfs1(1, dg, dp);
 
  vector<int> ans(n + 1);
 
  dfs2(1, dg, dp, ans);
 
  for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
  cout<<endl;
 
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  solve();
  return 0;
}
