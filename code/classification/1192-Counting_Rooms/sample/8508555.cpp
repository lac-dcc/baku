#include <bits/stdc++.h>
#include <utility>
 
using namespace std;
 
typedef int64_t ll;
typedef uint64_t ull;
 
// constexpr ll MOD = 1e9 + 7;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
 
  array<pair<int, int>, 4> moves = {
      make_pair(1, 0),
      make_pair(-1, 0),
      make_pair(0, 1),
      make_pair(0, -1),
  };
 
  vector<vector<bool>> visited(n, vector<bool>(m, false));
 
  int ans = 0;
 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch = grid[i][j];
      if (ch == '.' && !visited[i][j]) {
        ans++;
        queue<pair<int, int>> que;
        que.push({i, j});
        visited[i][j] = true;
 
        while (!que.empty()) {
          pair<int, int> cur = que.front();
 
          for (auto move : moves) {
            auto nxt =
                make_pair(cur.first + move.first, cur.second + move.second);
 
            if (nxt.first < 0 || nxt.first >= n || nxt.second < 0 ||
                nxt.second >= m)
              continue;
 
            char c = grid[nxt.first][nxt.second];
 
            if (c == '.' && !visited[nxt.first][nxt.second]) {
              que.push(nxt);
              visited[nxt.first][nxt.second] = true;
            }
          }
 
          que.pop();
        }
      }
    }
  }
 
  cout << ans << endl;
}
