#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, m, a, b;
  cin >> n >> m;
  vector<int> g[n + 1];
  int num[n + 1];
  int parent[n + 1];
  memset(num, -1, sizeof(num));
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  num[1] = 0;
  parent[1] = 1;
  while(!q.empty()){
    int x = q.front();
    for(int i : g[x]){
      if(num[i] == -1){
        num[i] = num[x] + 1;
        parent[i] = x;
        q.push(i);
      }
    }
    q.pop();
  }
  if(num[n] == -1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  vector<int> path;
  int x = n;
  while(parent[x] != x){
    path.push_back(x); 
    x = parent[x]; 
  }
  path.push_back(1);
  reverse(path.begin(), path.end());
  cout << path.size() << endl;
  for(int i : path) cout << i << " ";
  cout << endl;
}
