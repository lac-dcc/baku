#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif
 
const int N = 1e5;
vector<int> adj[N];
int type[N];
bool ok = 1;
 
void dfs(int u){
 
   int should = type[u] ^ 1;
   for(int v : adj[u]){
 
      if(type[v] == -1){
         type[v] = should;
         dfs(v);
      }else if(type[v] != should){
         ok = 0;
      }
   }
}
 
int main(){
 
  ios_base :: sync_with_stdio(0);
  cin.tie(NULL);
 
  int tt = 1;
  // cin>>tt;
  for(int tc = 1;tc<=tt;tc++){
   int n,m;
   cin>>n>>m;
 
   for(int i = 0;i<n;i++){
      adj[i].clear();
      type[i] = -1;
   }
   for(int i = 0;i<m;i++){
      int u,v;
      cin>>u>>v;
      u -= 1;
      v -= 1;
 
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
 
   ok = 1;
   for(int i = 0;i<n;i++){
      if(type[i] == -1){
         type[i] = 0;
         dfs(i);
      }
   }   
   if(!ok){
      cout<<"IMPOSSIBLE\n";
   }else{
      for(int i = 0;i<n;i++){
         cout<<(type[i] ^ 1) + 1<<(i == n - 1 ? "" : " ");
      }
   }
 
  }
  
  return 0;
 
 
}
