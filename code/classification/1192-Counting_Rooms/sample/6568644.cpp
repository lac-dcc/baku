#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <climits>
#include<stack>
using namespace std;
typedef long long int ll;
void solve(ll p);
// to sort in pair of sets etc!
struct compare
{
  bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const
  {
    if (a.first == b.first)
    {
      return (a.second < b.second);
    }
    else
    {
      return (a.first < b.first);
    }
  }
};
 
bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
  if (a.first == b.first)
  {
    return (a.second < b.second);
  }
  else
  {
    return (a.first < b.first);
  }
}
 
ll power(ll a, ll n,ll p)
{
  ll ans = 1;
  while (n)
  {
    if (n % 2 == 1)
    {
      ans = (ans * a)%p;
      n--;
    }
    else
    {
      a = (a * a)%p;
      n = n / 2;
    }
  }
  return (ans)%p;
}
 
ll GCD(ll a, ll b)
{
  if (a == 0)
    return b;
 
  if (b == 0)
    return a;
 
  return GCD(b, a % b);
}
 
ll modinverses(ll n,ll p)
{
  return power(n,p-2,p);
}
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
void dfs(ll x, ll y, vector<vector<ll> >&vis,vector<vector<char> >&adj,ll n,ll m)
{
  vis[x][y] = 1;
  for(ll i=0;i<4;i++)
  {
    ll newx = x + dx[i];
    ll newy = y + dy[i];
    if(newx>=0 && newy>=0 && newx<n && newy<m && vis[newx][newy]==0 && adj[newx][newy]=='.')
    {
        dfs(newx,newy,vis,adj,n,m);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t = 1;
  ll p=1;
  while (t--)
  {
    solve(p);
    p++;
  }
  return 0;
}
void solve(ll t)
{
  ll n,m;
  cin>>n>>m;
  vector<vector<char> >adj(n,vector<char>(m));
    vector<vector<ll> >vis(n,vector<ll>(m,0));
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m;j++)
    {
        cin>>adj[i][j];
    }
  }
  ll ans = 0;
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m;j++)
    {
        if(vis[i][j]==0 && adj[i][j]=='.')
        {
          ans++;
          dfs(i,j,vis,adj,n,m);
        }
    }
  }
  cout<<ans<<endl;
}
