#include<bits/stdc++.h>
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================
 
void dfs( vector<vector<int>>&dp,vector<vector<char>>&v,int i, int j){
  if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]=='#'||dp[i][j]==1)return;
  // m[{i,j}]=1;
  dp[i][j]=1;
  dfs(dp,v,i+1,j);
  dfs(dp,v,i,j+1);
  dfs(dp,v,i-1,j);
  dfs(dp,v,i,j-1);
}
 
void solve() {
  int i, j, n,nn;
  cin>>n>>nn;
  
  vector<vector<char>>v(n,vector<char>(nn));
  for(int i=0;i<n;i++){
    for(int j=0;j<nn;j++){
      cin>>v[i][j];
    }
  }
  int ans=0;
  vector<vector<int>>dp(n,vector<int>(nn,0));
  // cout<<ans<<endl;dfs(m,v,i+1,j);
  map<pair<int,int>,int>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<nn;j++){
      // cout<<i<<" "<<j<<endl;
      if(dp[i][j]==0&&v[i][j]=='.'){
        dfs(dp,v,i,j);
        ans++;
      }
    }
  }
  cout<<ans<<endl;return;
  
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}
 
 
