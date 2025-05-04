#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAXN = 2e5 + 1;
 
vector<vector<int>> adjList(MAXN);
vector<int> depths(MAXN);
 
int fn, fd;
 
void dfs(int node, int parent, int depth) {
  depths[node] = depth;
 
  for (int neighbor : adjList[node]) {
    if (neighbor != parent) {
      dfs(neighbor, node, depth + 1);
    }
  }
  if (depth > fd) {
    fn = node;
    fd = depth;
  }
}
 
int main() {
  int n;
  cin >> n;
 
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
 
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
 
  fd = 0;
  fn = -1;
  fill(depths.begin(), depths.end(), 0);
  dfs(1, -1, 0);
 
  int maxDepthNode = fn;
  fd = depths[maxDepthNode];
 
  fill(depths.begin(), depths.end(), 0);
 
  dfs(maxDepthNode, -1, 0);
 
  cout << fd << endl;
  return 0;
}
