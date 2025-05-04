#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) //x
#define A(x) DEBUG(assert(x))
#define PRINT(x) DEBUG(cerr << x)
#define PV(x) DEBUG(cerr << #x << " = " << x << '\n')
#define PV2(x) DEBUG(cerr << #x << " = " << x.first << ',' << x.second << '\n')
#define PAR(x) DEBUG(PRINT(#x << " = { "); for (auto y : x) PRINT(y << ' '); PRINT("}\n");)
#define PAR2(x) DEBUG(PRINT(#x << " = { "); for (auto [y, z] : x) PRINT(y << ',' << z << "  "); PRINT("}\n");)
typedef long long i64;
const int INF = 1000000007; //998244353;
 
struct S {
  int n;
  i64 s;
  vector<i64> a;
 
  void run() {
    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<i64> sums1, sums2;
    for (int i = 0; i < 1 << (n / 2); ++i) {
      i64 sum = 0;
      for (int j = 0; j < n / 2; ++j) {
        if (!(i & (1 << j))) continue;
        sum += a[j];
      }
      sums1.push_back(sum);
    }
    for (int i = 0; i < 1 << (n - n / 2); ++i) {
      i64 sum = 0;
      for (int j = 0; j < (n - n / 2); ++j) {
        if (!(i & (1 << j))) continue;
        sum += a[j + n / 2];
      }
      sums2.push_back(sum);
    }
    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());
    i64 ways = 0;
    for (auto i : sums1) {
      int l = lower_bound(sums2.begin(), sums2.end(), s - i) - sums2.begin();
      int r = upper_bound(sums2.begin(), sums2.end(), s - i) - sums2.begin();
      ways += i64(r - l);
    }
    cout << ways << '\n';
  }
};
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  auto sol = make_unique<S>();
  sol->run();
}
 
