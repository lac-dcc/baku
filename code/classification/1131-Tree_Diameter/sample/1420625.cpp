#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define db(x) cout << '>' << #x << ':' << x << endl;
#define sz(x) ((int)(x).size())
#define newl cout << "\n"
 
#define ll long long int
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>
 
#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
 
ll tc, n, m, k;
 
const ll maxn = 2e5 + 5;
 
vll parent(maxn);
vvll graph(maxn);
vll h(maxn);
vvll dp(maxn, vll(2));
ll ans = 0;
void dfs(ll u, ll p) {
  if (p != u)
    h[u] = h[p] + 1;
  else
    h[u] = 0;
  dp[u][0] = h[u];
  for (auto v : graph[u]) {
    if (v != p) {
      dfs(v, u);
      vll arr = {dp[u][0], dp[u][1], dp[v][0]};
      sort(arr.rbegin(), arr.rend());
      dp[u][0] = arr[0];
      dp[u][1] = arr[1];
    }
  }
  ans = max(ans, dp[u][1]+dp[u][0]-2*h[u]);
}
 
int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
 
  cin >> n;
 
  rep(i, 0, n - 1) {
    ll u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1, 1);
  cout << ans;
 
//  rep(u, 1, 5+1) {
//    db(u);
//    db(dp[u][0]);
//    db(dp[u][1]);
//    newl;
//  }
  return 0;
}
