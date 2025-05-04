#ifndef LOCAL
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <climits>
#endif
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; } sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; } eni(!=) cerr << boolalpha << i; ris; } eni(==) ris << range(begin(i), end(i)); } sim, class b dor(pair < b, c > d) { ris << "(" << d.first << ", " << d.second << ")"; } sim dor(rge<c> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
#define fix(a) fixed << setprecision(a)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define all(V) V.begin(), V.end()
#define rall(V) V.rbegin(), V.rend()
#define len(V) (int)V.size()
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n' 
 
 
void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> g(n);
  forn(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].push_back({c, b});
  }
 
  priority_queue<pair<ll, int>> q;
  vector<bool> was(n);
  vector<ll> dis(n, 2e18);
  dis[0] = 0;
  q.push({0, 0});
  while (!q.empty()){
    auto [dd, v] = q.top(); q.pop();
    if (was[v]) continue;
    was[v] = true;
    for (auto [d, to]: g[v]){
      if (dis[v] + d < dis[to]){
        dis[to] = dis[v] + d;
        q.push({-dis[to], to});
      }
    }
  }
  
  for(auto x: dis) cout << x << ' ';
  
}
 
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int t = 1;
  // cin >> t;
  forn(i, t){
    solve();
  }
}
 
/* 
 
 
 
*/
