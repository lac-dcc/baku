#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) //x
#define A(x) DEBUG(assert(x))
#define PRINT(x) DEBUG(cerr << x)
#define PV(x) DEBUG(cerr << #x << " = " << x << '\n')
#define PV2(x) DEBUG(cerr << #x << " = " << x.first << ',' << x.second << '\n')
#define PAR(x) DEBUG(PRINT(#x << " = { "); for (auto y : x) PRINT(y << ' '); PRINT("}\n");)
#define PAR2(x) DEBUG(PRINT(#x << " = { "); for (auto [y, z] : x) PRINT(y << ',' << z << "  "); PRINT("}\n");)
typedef int64_t i64;
const i64 INF = 1000000007LL; //998244353;
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  if (s1.length() < s2.length()) {
    swap(s1, s2);
  }
  int len1 = s1.length();
  int len2 = s2.length();
  vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= len1; ++i) {
    for (int j = 0; j <= len2; ++j) {
      if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); 
      if (i > 0 && j > 0) {
        dp[i][j] = min(dp[i][j],
          dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
      }
    }
  }
  cout << dp[len1][len2] << '\n';
}
 