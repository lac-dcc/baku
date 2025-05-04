#include<bits/stdc++.h>
#include<stdio.h>  
#define int long long
using namespace std;
 
void solve(){
  int n,m,q; cin>>n>>m>>q;
  vector<vector<int>> adj(n,vector<int> (n,LLONG_MAX));
  while(m--){
    int a,b,c; cin>>a>>b>>c;
    adj[a-1][a-1]=0, adj[b-1][b-1]=0;
    adj[a-1][b-1] = min(adj[a-1][b-1],c);
    adj[b-1][a-1] = min(adj[b-1][a-1],c);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][j] > (adj[i][k] + adj[k][j])  && (adj[k][j] != LLONG_MAX  && adj[i][k] != LLONG_MAX))
          adj[i][j] = adj[i][k] + adj[k][j];
      }
    }
  }
  while(q--){
    int a,b; cin>>a>>b;
    if(adj[a-1][b-1]==LLONG_MAX)
      cout<<-1<<endl;
    else
      cout<<adj[a-1][b-1]<<endl;
  }
}
 
int32_t main(){
  int t=1; //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
