#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 2e5 + 10;
vector<int> adj[MAX];
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;
int n, m;
 
bool dfs(int x, int par) {
  //cout << x << ' ' << par << '\n';
  visited[x] = true;
  for(int u : adj[x]) {
    if(u == par) continue;
    if(visited[u]) {
      cycle_start = u;
      cycle_end = x;
      return true;
    }
 
    parent[u] = x;
    if(dfs(u, x)) return true;
  }
 
  return false;
}
 
void find_cycle() {
  visited.assign(n+1, false);
  parent.assign(n+1, -1);
  cycle_start = -1;
  cycle_end = -1;
  //cout << 'a' << endl;
  for(int i=1; i<=n; i++) {
    if(!visited[i] && dfs(i, parent[i])) break;
  }
 
  if(cycle_start == -1) {
    cout << "IMPOSSIBLE";
  } else {
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for(int i=cycle_end; i != cycle_start; i = parent[i]) {
      cycle.push_back(i);
    }
    cycle.push_back(cycle_start);
 
    cout << cycle.size() << '\n';
    for(int i=0; i<cycle.size(); i++) {
      if(i != 0) cout << ' ';
      cout << cycle[i];
    }
  }
}
 
int main() {
  cin >> n >> m;
 
  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
 
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  find_cycle();
}
