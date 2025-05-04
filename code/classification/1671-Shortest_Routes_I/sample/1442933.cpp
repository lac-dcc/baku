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
 
const int mxN = 1e5 + 5;
const ll inf = 1e18;
 
vll vis(mxN, -1);
int id;
vector<pll> g[mxN];
vll dist(mxN, inf);
 
int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
 
  cin >> n >> m;
  rep(i, 0, m) {
    ll a, b, c;
    cin>>a>>b>>c;
    g[a].pb({b,c});
  }
 
  // run single source all destination = dijstra;
 
 
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dist[1] = 0;
  pq.push({0, 1});
  while(!pq.empty()) {
    auto top = pq.top(); pq.pop();
    ll u = top.s, cost = top.f;
    if(dist[u] != cost) continue;
    for(auto v:g[u]) {
      if(dist[v.f] > cost+v.s) {
        dist[v.f] = cost+v.s;
        pq.push({dist[v.f], v.f});
      }
    }
  }
  rep(u, 1, n+1) cout<<dist[u]<<" ";
 
  return 0;
}