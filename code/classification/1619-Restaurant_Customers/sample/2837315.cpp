#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ln "\n"
#define f first
#define s second
#define vi vector<int>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define ppll pair<ll, pll>
#define pppll pair<ll, ppll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << nline;
#else
#define debug(x) ;
#endif
void _print(ll x) { cerr << x; }
void _print(int x) { cerr << x; }
void _print(ld x) { cerr << x; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << " [ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << " [ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << " [ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << " [ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
 
void solve() {
  int n;
  cin >> n;
  set<pi> s;
  for (int i = 0; i < n; i++) {
    int in, out;
    cin >> in >> out;
    s.insert({in, 1});
    s.insert({out, -1});
  }
  int mx = 0, curr = 0;
  for (auto p : s) {
    curr = curr + p.s;
    mx = max(mx, curr);
  }
  cout << mx;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  ll t = 1;
  //	cin>>t;
  cout << fixed << setprecision(9);
  while (t--) {
    solve();
  }
  cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
