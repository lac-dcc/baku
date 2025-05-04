#include "bits/stdc++.h"
 
using namespace std;
 
const long long MAX = (long long)1e18 + 5;
 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n;
  int k;
  cin >> n >> k;
  vector<long long> v(k);
  for (auto& p : v) { cin >> p; }
  long long ans = 0;
  for (int i = 1; i < (1 << k); ++i) {
    long long product = 1;
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) {
        if (product > MAX / v[j]) { product = MAX; break; }
        product *= v[j];
      }
    }
    ans += (__builtin_popcount(i) & 1 ? +1LL : -1LL) * n / product;
  }
  cout << ans;
}