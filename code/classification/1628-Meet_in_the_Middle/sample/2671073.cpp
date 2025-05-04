#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,ssse3,sse4,mmx,popcnt")
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
 
  vector<ll> lsum {0};
  lsum.reserve(1<<L);
 
  ll sum = 0;
  for (int sl = 1; sl < 1<<L; ++sl) {
    int new_bits = sl & ~(sl-1);
    int lost_bits = (sl-1) & ~sl;
 
    while (new_bits) {
      int i = __builtin_ctz(new_bits);
      sum += a[i];
      new_bits ^= 1<<i;
    }
    while (lost_bits) {
      int i = __builtin_ctz(lost_bits);
      sum -= a[i];
      lost_bits ^= 1<<i;
    }
 
    lsum.push_back(sum);
  }
 
  sort(lsum.begin(), lsum.end());
  while (lsum.back() > x) lsum.pop_back();
  ll ans = 0;
  while (lsum.back() == x) lsum.pop_back(), ++ans;
 
  sum = 0;
  for (int sr = 1; sr < 1<<R; ++sr) {
    int new_bits = sr & ~(sr-1);
    int lost_bits = (sr-1) & ~sr;
 
    while (new_bits) {
      int i = __builtin_ctz(new_bits);
      sum += a[L+i];
      new_bits ^= 1<<i;
    }
    while (lost_bits) {
      int i = __builtin_ctz(lost_bits);
      sum -= a[L+i];
      lost_bits ^= 1<<i;
    }
 
    auto it0 = lower_bound(lsum.begin(), lsum.end(), x-sum);
    auto it1 = upper_bound(lsum.begin(), lsum.end(), x-sum);
    ans += it1-it0;
  }
 
  cout << ans << '\n';
}
