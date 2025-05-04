#include <bits/stdc++.h>
#define f first
#define s second
using ll = long long;
using namespace std;
const int mod = 1000000007;
int n, x;
int coins[100];
ll dp[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int c = coins[i];
    for (int w = 1; w <= x; w++) {
      if (w - c >= 0) {
        dp[w] += dp[w - c];
        dp[w] %= mod;
      }
    }
  }
  cout << dp[x] << "\n";
  return 0;
}
