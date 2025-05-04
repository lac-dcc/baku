#include <bits/stdc++.h>
#define pb push_back
typedef long long int ll;
typedef long double ld;
using namespace std;
ll M = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  t = 1;
  // cin >> t;
 
  while (t--) {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    pair<int, int> sr;
    pair<int, int> dt;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'A') sr = {i, j};
        if (grid[i][j] == 'B') dt = {i, j};
      }
    
    int vis[n][m];
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '.' && vis[i][j] == 0) {
          ans++;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            vis[u.first][u.second] = 1;
            if (u.first + 1 < n && u.second > -1 &&
                vis[u.first + 1][u.second] == 0 &&
                grid[u.first + 1][u.second] == '.') {
              vis[u.first + 1][u.second] = 1;
              q.push({u.first + 1, u.second});
            }
            if (u.first > -1 && u.second + 1 < m &&
                vis[u.first][u.second + 1] == 0 &&
                grid[u.first][u.second + 1] == '.') {
              vis[u.first][u.second + 1] = 1;
              q.push({u.first, u.second + 1});
            }
            if (u.first - 1 > -1 && u.second > -1 &&
                vis[u.first - 1][u.second] == 0 &&
                grid[u.first - 1][u.second] == '.') {
              vis[u.first - 1][u.second] = 1;
              q.push({u.first - 1, u.second});
            }
            if (u.first < n && u.second - 1 > -1 &&
                vis[u.first][u.second-1] == 0 &&
                grid[u.first][u.second-1] == '.') {
              vis[u.first][u.second - 1] = 1;
              q.push({u.first, u.second - 1});
            }
          }
        }
      }
    cout << ans << '\n';
  }
}
