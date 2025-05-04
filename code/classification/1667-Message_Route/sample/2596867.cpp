#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#define LOCAL
 
#define FOR(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define RFOR(i, l, r) for (int i = (int)(r); i >= (int)(l); --i)
#define FORN(i, n) FOR(i, 0, (n) - 1)
#define RFORN(i, n) RFOR(i, 0, (n) - 1)
#define FORE(x, a) for (const auto& x: a)
 
#define PB push_back
#define EB emplace_back
#define MP make_pair
 
#define FI first
#define SE second
 
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(ALL(x), 0)
#define MIN(x) min_element(ALL(x))
#define MAX(x) max_element(ALL(x))
#define SZ(x) ((int)(x).size())
 
#ifdef LOCAL
#define DEBUG(x) cerr << #x << " = " << x << '\n'
#define DEBUG2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y <<'\n'
#define DEBUGV(x) cerr << #x << " = "; FORE(item, (x)) cerr << *item << " "; cerr <<"\n"
#define DEBUGARR(x, size) cerr << #x << " = "; FORN(i, (size)) cerr << x[i] << ' '; cerr << '\n'
#else
#define DEBUG(x)
#define DEBUG2(x, y)
#define DEBUGV(x)
#endif
 
#define MAKE(type, x) type x; cin >> x
#define MAKE2(type, x, y) type x, y; cin >> x >> y
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
const ld EPS = 1e-6;
const int MOD = 1e9 + 7; // 998244353
const ld PI = acos((ld) -1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
inline void mini(T& a, const T& b) { a = min(a, b); }
 
template<typename T>
inline void maxi(T& a, const T& b) { a = max(a, b); }
 
template<typename U, typename V>
ostream& operator<<(ostream& out, const pair<U, V>& p) {
  out << p.FI << ' ' << p.SE;
  return out;
}
 
template<typename T>
istream& operator>>(istream& in, vector<T>& vec) {
  FORN(i, vec.size()) in >> vec[i];
  return in;
}
 
template<typename T>
inline void print(const vector<T>& vec, char sep = ' ', char end = '\n') {
  if (!vec.empty()) {
    FORN(i, vec.size() - 1) cout << vec[i] << sep;
    cout << vec.back();
  }
  cout << end;
}
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int MAX_N = 100000;
 
int n, m;
vi g[MAX_N];
char used[MAX_N];
int backtrack[MAX_N];
 
inline void Solve(int test_idx) {
  cin >> n >> m;
  FORN(i, n) {
    g[i].clear();
    used[i] = 0;
    backtrack[i] = -1;
  }
  FORN(i, m) {
    MAKE2(int, u, v);
    --u;--v;
    g[u].PB(v);
    g[v].PB(u);
  }
 
  queue<int> q{{0}};
  used[0] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    bool found = false;
    FORE(u, g[v]) {
      if (used[u]) continue;
      q.push(u);
      used[u] = 1;
      backtrack[u] = v;
      if (u == n - 1) {
        found = true;
        break;
      }
    }
    if (found) break;
  }
 
  if (!used[n - 1]) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int cur = n - 1;
  vi ans;
  while (cur != -1) {
    ans.PB(cur + 1);
    cur = backtrack[cur];
  }
  cout << ans.size() << '\n';
  reverse(ALL(ans));
  print(ans);
}
 
int main() {
  //#define DEBUG_OUTPUT
#ifndef DEBUG_OUTPUT
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
#endif
  int test_cnt = 1;
//#define CASES
#ifdef CASES
  cin >> test_cnt;
#endif
  FORN(i, test_cnt) {
    Solve(i);
  }
}
