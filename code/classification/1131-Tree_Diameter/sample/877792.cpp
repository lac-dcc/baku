// WIP
 
#include <bits/stdc++.h>
using namespace std;
 
// Utility
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, X, Y) for (int I = (X); I < (Y); I++)
using ll = int64_t;
using ull = uint64_t;
template<typename T> struct is_container {
template<typename C> static char test(typename C::const_iterator*); template<typename> static int test(...);
static bool const value = sizeof(test<T>(nullptr)) == sizeof(char) && !std::is_same<std::string, T>::value;
};
namespace std {
template<class ...Ts>        istream& operator>>(istream& i, tuple<Ts...>& x) { apply([&](auto&&... ys){ ((i >> ys), ...); }, x); return i; }
template<class T1, class T2> istream& operator>>(istream& i, pair<T1, T2>& x) { i >> x.first >> x.second; return i; }
template<class T, enable_if_t<is_container<T>::value, int> = 0>
istream& operator>>(istream& i, T& x) { for (auto& y : x) { i >> y; } return i; }
}
 
// Debugging
#define DD(X) std::cout << #X ": " << (X) << std::endl << std::flush
#define DD2(X) std::cout << #X ":" << std::endl; for (auto x : (X)) { std::cout << x << std::endl << std::flush; }
namespace std {
template<class ...Ts>        ostream& operator<<(ostream& o, const tuple<Ts...>& x) { o << "("; apply([&](auto&& y, auto&&... ys){ o << y; ((o << ", " << ys), ...); }, x); o << ")"; return o; }
template<class T1, class T2> ostream& operator<<(ostream& o, const pair<T1, T2>& x) { o << tie(x.first, x.second); return o; }
template<class T, enable_if_t<is_container<T>::value, int> = 0>
ostream& operator<<(ostream& o, const T& x) { o << "{"; for (auto it = x.begin(); it != x.end(); it++) { if (it != x.begin()) { o << ", "; } o << *it; } o << "}"; return o; }
}
 
// Main
void mainCase() {
  int n; // <= 10^6
  cin >> n;
 
  vector<tuple<int, int>> edges(n - 1, {0, 0});
  cin >> edges;
 
  vector<vector<int>> adj(n);
  for (auto [x, y] : edges) {
    x--; y--;
    adj[x].push_back(y); adj[y].push_back(x);
  }
 
  vector<int> depths(n, -1);
  function<void(int)> dfs = [&](int v) {
    for (auto u : adj[v]) {
      if (depths[u] == -1) {
        depths[u] = depths[v] + 1;
        dfs(u);
      }
    }
  };
 
  // 1st DFS
  depths[0] = 0;
  dfs(0);
  // DD(depths);
 
  // Pick deepest
  int v1 = 0, d1 = 0;
  FOR(v, 0, n) {
    if (depths[v] > d1) {
      v1 = v; d1 = depths[v];
    }
  }
  // DD(tie(v1, d1));
 
  // 2nd DFS
  fill(ALL(depths), -1);
  depths[v1] = 0;
  dfs(v1);
  // DD(depths);
 
  // Pick deepest
  int res = *max_element(ALL(depths));
  cout << res << endl;
}
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // [ Single case ]
  mainCase();
  return 0;
  // [ Multiple cases ]
  // int t;
  // cin >> t;
  // FOR(i, 0, t) { mainCase(); }
  // return 0;
}
 
/*
python misc/run.py cses/tree_algorithms/task1131/main.cpp --check
 
%%%% begin
5
1 2
1 3
3 4
3 5
%%%%
3
%%%% end
*/
