#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int color[N];
 
bool dfs(int src){
  visited[src] = 1;
  for(int adj_node : adj_list[src]){
    if(visited[adj_node] == 0){
      if(color[src] == 1) color[adj_node] = 2;
      else color[adj_node] = 1;
      visited[adj_node] = 1;
      bool is_colorable = dfs(adj_node);
      if(!is_colorable){
        return false;
      }
    }else{
      if(color[adj_node] == color[src]) return false;
    }
  }
  return true;
}
 
int main(){
  int nodes, edges;
  cin>> nodes>> edges;
  for(int i = 0; i<edges; i++){
    int u, v;
    cin>> u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  bool  is_colorAble = true;
  for(int i = 1; i<= nodes; i++){
    if(visited[i] == 0){
      color[i] = 1;
      int ok = dfs(i);
      if(!ok){
        is_colorAble = false;
        break;
      }
    }
  }
if(!is_colorAble) cout << "IMPOSSIBLE\n";
else {
for(int i = 1; i<=nodes; i++){
  cout << color[i] << " ";
}}
 
}
