#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <deque>
#include <unordered_set>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
// #define ll long long
#define int long long
#define ld long double
#define F first
#define S second
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define pb puhave_back
#define MP make_pair
#define endl '\n'
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void print(vector<int> &a, int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << "\n";
}
 
int binaryexp(int a, int b)
{
  int ans = 1;
  while (b)
  {
    if (b & 1)
    {
      ans = (1LL * ans * a) % MOD;
    }
    b >>= 1;
    a = (1LL * a * a) % MOD;
  }
  return ans;
}
 
int sumof(int n)
{
  int sum = 0;
  while (n != 0)
  {
    sum += (n % 10);
    n = (n / 10);
  }
  return sum;
}
 
vector<int>subor;
 vector<vector<int>>g;
 vector<int>dist;
 int dia=0;
 
void dfs(int node,int par,int dd){
dist[node]=dd;
  for(auto ch:g[node]){
   if(ch!=par){
    dfs(ch,node,dd+1);
    
   }   
  }
 
}
void solve()
{
 
  int n;
  cin>>n;
  subor=vector<int>(n,0);
 g=vector<vector<int>>(n);
 dist=vector<int>(n,1e9);
  rep(i,0,n-2){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0,-1,0);
int mixi=-1,node=-1;
for(int i=0;i<n;i++){
  if(dist[i]>mixi){
      mixi=dist[i];
      node=i;
  }
}
 
 dfs(node,-1,0);
int ans=0;
 for(int i=0;i<n;i++){
   ans=max(ans,dist[i]);
 }
cout<<ans<<endl;
 
}
 
signed main()
{
  IOS;
 
  int t;
  t=1;
  // cin >> t;
 
  while (t--)
  {
    solve();
 
  }
}
