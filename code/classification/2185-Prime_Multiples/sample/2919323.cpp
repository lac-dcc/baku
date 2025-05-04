#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
#define ll uint64_t
int MOD = 1e9 + 7;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  ll n, k;
  cin >> n >> k;
  vector<ll> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  ll power = 1ll << k;
  for (ll i = 1; i < power; ++i) {
    ll lcm1 = 1;
    ll number = i;
    ll j = 0;
    ll minus_one = -1;
    while (number > 0) {
      if (number % 2 == 1) {
        if (lcm1 > n / a[j]) {
          lcm1 = n + 1;
        } else {
          lcm1 *= a[j];
        }
        minus_one *= -1;
      }
      number /= 2;
      j++;
    }
    sum += (n / lcm1) * minus_one;
  }
  cout << sum;
}