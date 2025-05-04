#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
 
vector<int> G[MAXN];
queue<int> q;
int dist[MAXN], pred[MAXN];
 
void findPath(int node) {
  if(node == 1)
    cout << "1 ";
  else {
    findPath(pred[node]);
    cout << node << ' ';
  }
}
 
int main() {
  int n, m;
 
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
 
  pred[1] = -1;
  dist[1] = 1;
  q.push(1);
 
  while(!q.empty()) {
    int node = q.front();
    q.pop();
 
    for(int son : G[node])
      if(dist[son] == 0) {
        dist[son] = dist[node] + 1;
        pred[son] = node;
        q.push(son);
      }
  }
 
  if(dist[n] == 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
 
  cout << dist[n] << '\n';
  findPath(n);
 
  return 0;
}


