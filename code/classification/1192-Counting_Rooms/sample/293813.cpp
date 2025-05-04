#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
 
  int sol = n * m;
 
  vector<int> graph[n * m];
 
  string prev_line(m, '#');
  for (int i = 0; i < n; ++i) {
    string line;
    cin >> line;
 
    for (int j = 0; j < m; ++j) {
      if (line[j] == '#') {
        --sol;
        continue;
      }
      if (prev_line[j] == '.') {
        graph[i * m + j].push_back((i - 1) * m + j);
        graph[(i - 1) * m + j].push_back(i * m + j);
      }
      if (j) if (line[j - 1] == '.') {
        graph[i * m + j].push_back((i * m + j) - 1);
        graph[(i * m + j) - 1].push_back(i * m + j);
      }
    }
 
    prev_line = line;
  }
 
  //bool visited[n * m] = {};
  vector<bool> visited(n * m, false);
  for (int i = 0; i < n * m; ++i) {
    if (visited[i]) {
      --sol;
      continue;
    }
 
    vector<int> s;
    s.push_back(i);
 
    while (!s.empty()) {
      if (visited[s.back()]) {
        s.pop_back();
        continue;
      }
 
      visited[s.back()] = true;
 
      for (int child : graph[s.back()])
        if (!visited[child]) s.push_back(child);
    }
  }
 
  cout << sol << endl;
}
