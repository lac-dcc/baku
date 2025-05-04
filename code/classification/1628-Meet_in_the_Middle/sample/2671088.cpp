#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for (int &v : a) cin >> v;
 
  int L = (n+1)/2;
  int R = n/2;
 
  vector<ll> lsum(1<<L), rsum(1<<R);
  for (int s = 1; s < 1<<L; ++s) {
    int bit = __builtin_ctz(s);
    lsum[s] = lsum[s^(1<<bit)] + a[bit];
  }
 
  sort(lsum.begin(), lsum.end());
  while (lsum.back() > x) lsum.pop_back();
  ll ans = 0;
  while (lsum.back() == x) lsum.pop_back(), ++ans;
 
  for (int s = 1; s < 1<<R; ++s) {
    int bit = __builtin_ctz(s);
    rsum[s] = rsum[s^(1<<bit)] + a[L+bit];
 
    auto it0 = lower_bound(lsum.begin(), lsum.end(), x-rsum[s]);
    auto it1 = upper_bound(lsum.begin(), lsum.end(), x-rsum[s]);
    ans += it1-it0;
  }
 
  cout << ans << '\n';
}
