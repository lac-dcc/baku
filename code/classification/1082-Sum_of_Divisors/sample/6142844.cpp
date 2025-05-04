#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "templates/debug.h"
#else
#define dbg(x...)
#endif
 
const int64_t MOD = int(1e9) + 7;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int64_t n; cin >> n;
  int64_t ans = 0;
  const int64_t inv = (MOD + 1) / 2;
  for (int64_t i = 1; i <= n; i++) {
    int64_t nxt = n / (n / i);
    int64_t s = ((nxt - i + 1) % MOD) * ((i + nxt) % MOD) % MOD * inv % MOD;
    (ans += n / i % MOD * s % MOD) %= MOD;
    i = nxt;
  }
  cout << ans << '\n';
}