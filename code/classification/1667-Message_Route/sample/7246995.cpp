#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> adj[100001];
bool visited[100001];
int dis[100001];
int from[100001];
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
 
  // Prepare adjacency list
  for(int i=0; i<m; i++) {
    int u,v; cin>>u>>v; u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  queue<int> q;
  q.push(0); visited[0]=1; dis[0]=0;
 
  while(!q.empty()) {
    int s = q.front(); q.pop();
    for(int u: adj[s]) {
      if(visited[u]) continue;
      visited[u]=1;
      dis[u]=dis[s]+1;
      from[u]=s;
      q.push(u);
    }
  }
 
  if(!visited[n-1]) cout<<"IMPOSSIBLE\n";
  else {
    cout<<dis[n-1]+1<<'\n';
    vector<int> v;
    int last=n-1;
    while(1) {
      v.push_back(last+1);
      if(last==0) break;
      last=from[last];  
    }
    reverse(v.begin(),v.end());
    for(int x:v) cout<<x<<' ';
  }
}
