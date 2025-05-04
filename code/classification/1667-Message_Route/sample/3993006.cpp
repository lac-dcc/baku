#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
#define N 100005
vector<bool>vis(N,false);
vector<int>adj[N];
vector<int>dis(N);
vector<int>p(N);
queue<int>q;
 
int main(){
  int n,m;
  cin>>n>>m;
  int u,v;
  for(int i=0;i<m;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  q.push(1);
  vis[1]=true;
  while(!q.empty()){
    int k=q.front();
    q.pop();
    for(int i:adj[k]){
      if(vis[i]==false){
        dis[i]=dis[k]+1;
        vis[i]=true;
        p[i]=k;
        q.push(i);
      }
    }
  }
  if(vis[n]==false){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  int k=n;
  int dist=dis[n];
  vector<int>ans(dist+1);
  for(int i=dist;i>=0;i--){
    ans[i]=k;
    k=p[k];
  }
  cout<<dist+1<<"\n";
  for(int i=0;i<=dist;i++){
    cout<<ans[i]<<" ";
  }
}
