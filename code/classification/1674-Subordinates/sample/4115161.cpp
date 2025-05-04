#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
 
int n;
int dp[int(1e6)];
vi adj[int(1e6)];
int dfs(int n)
{
  if(adj[n].size() == 0)
  {
    return 0;
  }
  for(auto child : adj[n])
  {
    dp[n] += 1+dfs(child);
  }
  return dp[n];
}
void solve()
{
  int i,j,k;
  cin>>n;
  for(i=1;i<n;i++)
  {
    cin>>j;
    adj[j].push_back(i+1);
  }
  memset(dp, 0, sizeof dp);
  dfs(1);
  for(i=1;i<=n;i++)cout << dp[i] << " \n"[i==n];
  
  
}
int main()
{
  int t = 1;
  while(t--)
    solve();
  return 0;
}
