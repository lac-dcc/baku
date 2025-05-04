#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<bool> vis;
 
void dfs(int node){
  vis[node]=true;
  for(int neb: adj[node]){
    if (!vis[neb]){
      dfs(neb);
    }
  }
}
 
int main(){
  int n,e;
  cin>>n>>e;
 
  adj = vector<vector<int>>(n+1);
  vis = vector<bool>(n+1,false);
  for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  int cc=0;
  vector<pair<int,int>> nroads;
  vector<int> incomponent;
  for(int i=1;i<=n;i++){
    if (!vis[i]) {
      incomponent.push_back(i);
      dfs(i);
      cc++;
    }
  }
 
  cout<<cc-1<<'\n';
  if (cc-1>0){
    for(int i=0;i<cc-1;i++){
    cout<<incomponent[i]<<' '<<incomponent[i+1]<<'\n';
  } 
  }
}
