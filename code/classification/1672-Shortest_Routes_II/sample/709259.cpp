#include <bits/stdc++.h>
using namespace std;
 
int n, m, q;
vector<vector<long long>> dist(501, vector<long long>(501, -1));
 
bool Smaller(long long a, long long b) {
  return (a < 0 || a > b);
}
 
void Floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (dist[i][k] < 0) {
        continue;
      }
      for (int j = 1; j <= n; ++j) {
        if (dist[k][j] < 0)  {
          continue;
        }
 
        long long len = dist[i][k] + dist[k][j];
        if (Smaller(dist[i][j], len)) {
          dist[i][j] = len;
          dist[j][i] = len;
        }
      }
    }
  }
 
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    dist[i][i] = 0;
  }
 
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
 
    if (Smaller(dist[a][b], c)) {
      dist[a][b] = c;
      dist[b][a] = c;
    }
  }
 
  Floyd();
 
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << dist[a][b] << endl;
  }
 
  return 0;
}
