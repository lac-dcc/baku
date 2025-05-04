#include <bits/stdc++.h>
using namespace std;
#define DEV_MODE_PRAGMAS
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("bmi,bmi2,popcnt,lzcnt,tune=native")
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template <class T> using v = vector<T>;
using ll = long long;
using dd = long double;
using int2 = pair<int, int>;
using ll2 = pair<ll, ll>;
using dd2 = pair<dd, dd>;
 
#define f first
#define s second
#define all(x) begin(x), end(x)
istream &__cin = cin;
#ifdef DEV_MODE
#include "debug.h"
__cinwrapper __cin_wrapper;
#define cin __cin_wrapper
#else
#define dbg(...)
#define dbg2d(...)
#endif
 
template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T> istream &operator>>(istream &in, v<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*
 _______________________________________
( If you don't fail at least 90% of the )
( time, you're not aiming high enough.  )
(                                       )
( - Alan Kay                            )
 ---------------------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
 
const bool INTERACTIVE = false;
const bool MULTITEST = false;
/******************************************************************************/
 
#pragma region templates
const int MOD = 1e9 + 7;
struct Space {
  unsigned int nr;
 
  constexpr Space() : nr(1) {
    for (int i = 0; i < 5; i++)
      nr *= 2 - MOD * nr;
  }
};
 
struct mont {
  static constexpr Space space = Space();
  unsigned int val;
 
  template <class T> constexpr mont(T v) : val(transform(v)) {}
 
  explicit operator ll() { return reduce(val); }
  explicit operator int() { return reduce(val); }
 
  static unsigned int reduce(unsigned long long x) {
    unsigned int q = (unsigned int)x * space.nr;
    unsigned int m = ((unsigned long long)q * MOD) >> 32;
    return (unsigned int)((x >> 32) + MOD - m);
  }
 
  static constexpr unsigned int transform(unsigned int x) {
    return ((unsigned long long)x << 32) % MOD;
  }
  friend mont &operator+=(mont &a, mont b) {
    a.val += b.val;
    if (a.val >= MOD)
      a.val -= MOD;
    return a;
  }
  friend mont &operator*=(mont &a, mont b) {
    a.val = reduce((unsigned long long)a.val * b.val);
    return a;
  }
  friend mont &operator/=(mont &a, mont b) { return a *= pow(b, MOD - 2); }
 
  friend mont operator+(mont a, mont b) { return a += b; }
  friend mont operator*(mont a, mont b) { return a *= b; }
  friend mont operator/(mont a, mont b) { return a /= b; }
 
  static mont pow(mont a, unsigned long long b) {
    mont acc = 1;
    while (b) {
      if (b & 1)
        acc *= a;
      a *= a;
      b >>= 1;
    }
 
    return acc;
  }
  friend mont pow(mont a, unsigned long long b) { return mont::pow(a, b); }
};
#pragma endregion templates
 
void solve() {
  ll n;
  cin >> n;
  ll m = sqrt(n);
  unsigned long long sum = mont((m * (m + 1) / 2) % MOD).val;
  constexpr mont i2 = 500000004;
  constexpr mont three = 3, m1 = MOD - 1;
  unsigned long long mng = 0, m3i = 0;
  __uint128_t mulsum = 0;
  for (ll i = 1; i <= m; i++) {
    mont n2 = (n / i) % MOD;
    m3i += three.val;
    mng += m1.val;
    sum += n2.val;
    mulsum += ((__uint128_t)n2.val + m3i) * ((__uint128_t)n2.val + mng);
  }
  sum += mont::reduce((unsigned long long)(mulsum % MOD));
  sum %= MOD;
  cout << (mont::reduce(mont::reduce(sum * i2.val))) % MOD;
}
 
int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "misc-in.txt");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int t;
  if (MULTITEST)
    cin >> t;
  else
    t = 1;
  while (t--)
    solve();
 
#ifdef DEV_MODE
  debug_exit(INTERACTIVE);
#endif
}
#ifdef DEV_MODE
#include "debug.cpp"
#endif
