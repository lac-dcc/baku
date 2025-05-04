#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
 
#define ll long long
#define ar array<int>
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
 
using namespace std;
 
//https://cses.fi/problemset/task/1132
 
const int mxn=2e5+5;
vector<vector<int>> g(mxn,vector<int>());
vector<vector<int>> dp(2,vector<int>(mxn));
int N,mxNode,mxNode2;
 
int dfs(int c,int p,int t,int i) {
  dp[i][c]=t;
  int farthestNode=-1;
  for(auto& x: g[c]) {
    if(x!=p) {
      int possibleFarthestNode=dfs(x,c,t+1,i);
      if(farthestNode==-1 or dp[i][farthestNode]<dp[i][possibleFarthestNode])
         farthestNode=possibleFarthestNode;
    }
  }
  return (farthestNode==-1 ? c : farthestNode);
}
 
void solve() {
  cin>>N;
  for(int i=1;i<N;i++) {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b),g[b].push_back(a);
  }
  mxNode=dfs(1,0,0,0);
  mxNode2=dfs(mxNode,0,0,0);
  dfs(mxNode2,0,0,1);
  for(int i=1;i<=N;i++)
    cout<<max(dp[0][i],dp[1][i])<<" ";
  cout<<endl;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
 
int T=1;
//cin>>T;
while(T--)
    solve();
 
return 0;
}
