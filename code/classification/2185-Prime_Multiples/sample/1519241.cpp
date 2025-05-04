#include <bits/stdc++.h>
 
using namespace std;
 
#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'
 
constexpr int INF = (sizeof(int) == 4 ? 1e9 : 2e18) + 1e5;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 3;
 
// #define MULTIPLE_TEST_CASES
void solve() {
  int k;
  cin >> k;
  int n;
  cin >> n;
  vi arr(n);
  for (int &x : arr)
    cin >> x;
 
  int ans = 0;
  for (int mask = 1; mask < (1ll << n); ++mask) {
    int cnt = 0, g = -1, ok = true;
    __int128_t l = 1;
    for (int j = 0; j < n; ++j) {
      if (!((mask >> j) & 1ll))
        continue;
      ++cnt;
      if (g == -1) {
        g = l = arr[j];
      } else {
        g = gcd(arr[j], g);
        l = arr[j] * l / g;
        if (l > k) {
          ok = false;
          break;
        }
      }
    }
    if (!ok)
      continue;
    if (cnt & 1)
      ans += k / l;
    else
      ans -= k / l;
  }
 
  cout << ans << endl;
}
 
signed main() {
  // const string FILE_NAME = "";
  // freopen((FILE_NAME + string(".in")).c_str(), "r", stdin);
  // freopen((FILE_NAME + string(".out")).c_str(), "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
 
  int t = 1;
#ifdef MULTIPLE_TEST_CASES
  cin >> t;
#endif
  while (t--)
    solve();
}