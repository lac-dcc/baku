#include<bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define inv(i,a,b) for(ll i=a;i>=b;i--)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const int mod = 1e9 + 9;
const long long INF = 1e18 + 1;
const int mxn = 2e5 + 5;
void addself(ll& a,ll b)
{
    a+=b;
    if(a >= mod)
    a-=mod;
}
vector<vector<int>>g(mxn);
// int dp[mxn][2];
// void solveit(int v,int p)
// {
//  vector<int>pre,suf;
//  dp[v][0] = dp[v][1] = 0;
//  bool leaf = 1;
//  for(auto u : g[v])
//  {
//      if(u!=p)
//      {
//          leaf = 0;
//          solveit(u,v);
//      }
//  }
//  if(leaf)
//  return;
//  for(auto u : g[v])
//  {
//      if(u!=p)
//      {
//          pre.pb(max(dp[u][0] , dp[u][1]));
//          suf.pb(max(dp[u][0] , dp[u][1]));
//      }
//  }
//  rep(i,1,pre.size())
//  pre[i]+=pre[i-1];
//  inv(i,suf.size()-2,0)
//  suf[i]+=suf[i+1];
 
//  dp[v][0] = suf[0];
//  int c = 0;
//  for(auto u : g[v])
//  {
//      if(u != p){
//       int temp = dp[u][0];
//      if(c>0)
//      temp+=pre[c-1];
//      if(c<suf.size()-1)
//      temp+=suf[c+1];
//      dp[v][1] = max(dp[v][1] , temp + 1);
//      c++;
//      }
//  }
//  return;
 
 
 
 
 
 
// }
 
void dfs1(int v,int p,int dis,int &res,int& node)
{
    bool leaf = true;
    for(auto u : g[v])
    {
        if(u!=p)
        {
            leaf = false;
            dfs1(u,v,dis+1,res,node);
        }
    }
    if(leaf)
    {
        if(dis > res)
        {
            node = v;
            res = dis;
        }
    }
    return;
}
 
void solve()
{
  int n,u,v;
  cin>>n;
  for(int i = 1;i<=n-1;i++)
  {
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
  }
  int node = 1;
  int res = 0;
  dfs1(1,-1,0,res,node);
  res = 0;
  dfs1(node,-1,0,res,node);
  cout<<res;
 
  
  
}
int main()
{
    fastIO;
    int t = 1;
    //cin>>t;
    while(t--)
    {
      solve();
        
    }
    return 0;
}
