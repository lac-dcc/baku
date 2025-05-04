#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<int>>& graph, vector<int>& visited, int i){
  for (int& city : graph[i]){
    if (!visited[city]){
      visited[city] = 1;
      dfs(graph, visited, city);
    }
  }
}
 
int main (int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n+1);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> cities;
  vector<int> visited(n+1, 0);
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      visited[i] = 1;
      dfs(graph, visited, i);
      cities.push_back(i);
    }
  }
 
  cout << cities.size()-1 << endl;
  for (int i = 1; i < cities.size(); i++){
    cout << cities[i] << " " << cities[i-1];
    cout << endl;
  }
  return 0;
}
