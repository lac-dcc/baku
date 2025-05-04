#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
#ifndef _DEBUG
#define endl '\n'
#endif
#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ckmin(x, y) x = min((x), (y))
#define ckmax(x, y) x = max((x), (y))
 
// clang-format off
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
// clang-format on
 
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
 
void solve(ll _t) {
  ll n;
  cin >> n;
 
  vector<vector<ll>> adj(n);
  for (ll i = 1; i < n; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  vector<ll> dist(n);
  auto dfs = [&](auto &&dfs, ll cur, ll par, ll d) -> void {
    dist[cur] = d;
    for (ll x : adj[cur]) {
      if (x == par) continue;
      dfs(dfs, x, cur, d + 1);
    }
  };
  dfs(dfs, 0, -1, 0);
 
  ll i = max_element(all(dist)) - begin(dist);
  dfs(dfs, i, -1, 0);
  auto di = dist;
 
  ll j = max_element(all(dist)) - begin(dist);
  dfs(dfs, j, -1, 0);
  auto dj = dist;
 
  for (ll i = 0; i < n; ++i) {
    cout << max(di[i], dj[i]) << " ";
  }
  cout << endl;
}
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
 
  ll T = 1;
  /* cin >> T; */
  for (ll t = 1; t <= T; ++t) solve(t);
}
