#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int f = 1;
void bfs(int i, vector<int> adj[], vector<int>&team, int mark) {
  if(team[i]) {
    if(team[i]!=mark)
      f = 0;
    return;
  }
  team[i] = mark;
  for(auto node : adj[i]) {
    bfs(node, adj, team, (mark == 1) ? 2 : 1);
  }
}
signed main() {
  cin >> n >> m;
  vector<int> adj[n+1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> team(n + 1, 0);
  for (int i = 1; i <= n;i++) {
    if(f==0)
      break;
    if(team[i]==0)
      bfs(i, adj, team,1);
  }
  if(!f)
    cout << "IMPOSSIBLE" << endl;
  else
    for (int i = 1; i <= n;i++)
      cout << team[i] << " ";
}
