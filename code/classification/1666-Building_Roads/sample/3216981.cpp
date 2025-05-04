#include "bits/stdc++.h"
using namespace std;
 
#define ll long long 
#define rep(i,x,y) for(ll i=x;i<=y;i++)
const int mxn=1e5+2;
vector<int>adj[mxn];
bool vis[mxn];
 
void dfs(int node){
  vis[node]=1;
  for(auto child:adj[node]){
    if(!vis[child])
      dfs(child);
  }
}
 
int main(){
 int n,m;cin>>n>>m;
 rep(i,0,m-1){
  int a,b;cin>>a>>b;
  a--,b--;
  adj[a].push_back(b);
  adj[b].push_back(a);
 }
 int hm=0;
vector<int>ans;
rep(i,0,n-1){
  if(!vis[i]){
    dfs(i);
    if(i!=0)ans.push_back(i+1),hm++;
  }
}
cout<<hm<<endl;
for(auto i:ans)
   cout<<"1 "<<i<<endl;
}
 
