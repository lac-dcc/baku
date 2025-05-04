#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  string n, m;
  cin >> n >> m;
 
  int N = n.size(), M = m.size();
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
  for (int i = 0; i < N; ++i) dp[i][M] = N - i;
  for (int i = 0; i < M; ++i) dp[N][i] = M - i;
  dp[N][M] = 0;
 
  for (int i = N - 1; i >= 0; --i) {
    for (int j = M - 1; j >= 0; --j) {
      if (n[i] == m[j]) {
        dp[i][j] = dp[i + 1][j + 1];
      } else {
        dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
      }
    }
  }
 
  cout << dp[0][0] << endl;
 
  return 0;
}
