#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define endl "\n"
#define rep(i,x,y) for(int i=x; i<=y; i++)
const int mxn=2e5+5;
const int mod=1e9+7;
 
vector<int>adj[mxn];
vector<array<int,2>>dp1(mxn);
vector<int>dp2(mxn);
 
void dfs2(int n,int p)
{ 
  for(int c:adj[n]){
    if(c==p)continue;
      dp2[c]=1+dp2[n];
    if(1+dp1[c][1]!=dp1[n][1]){
      // cout<<1+dp1[c][1]<<" "<<dp1[n][1]<<endl;
      dp2[c]=max(dp2[c],1+dp1[n][1]);
      // cout<<dp2[1]<<endl;
    }
    else{
      dp2[c]=max(dp2[c],1+dp1[n][0]);
    }
    dfs2(c,n);
  }
}
// 8 min>
void dfs(int n,int p){
  for(auto c:adj[n]){
    if(c==p)continue;
    dfs(c,n);
    int a=dp1[c][1]+1;
    if(a>dp1[n][0]){
      dp1[n][0]=a;
      if(dp1[n][0]>dp1[n][1])
        swap(dp1[n][0],dp1[n][1]);
  }
}
}
void solve(){
 int n;
 cin>>n;
 for(int i=0;i<n-1;i++){
   int a,b;
   cin>>a>>b;
   --a,--b;
   adj[a].push_back(b);
   adj[b].push_back(a);
 }
 dfs(0,-1);
 dfs2(0,-1);
for(int i=0;i<=n-1;i++)cout<<max(dp2[i],dp1[i][1])<<" ";
  cout<<endl;
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int l=1;
  // cin >> l;
  for (int i = 0; i < l; i++) solve();
}
