#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include <limits>
#include <iomanip>
#include <cassert>
#include <numeric>
#include <chrono>
#include <random>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debug_pii(x) cerr << "(" << x.first << "," << x.second << ")";
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define F first
#define S second
 
// template<typename _Ty1, typename _Ty2>
// ostream& operator<<(ostream& _os, const pair<_Ty1, _Ty2>& _p) {
//     _os << '(' <<_p.first << ',' << _p.second << ')';
//     return _os;
// }ṅ
//
// template<typename _Ty1, typename _Ty2>
// istream& operator>>(istream& _is, pair<_Ty1, _Ty2>& _p) {
//     _is >> _p.first >> _p.second;
//     return _is;
// }
 
const long double pi = 3.141592653589793;
const int mod = 1e9 + 7;
 
const int nmax = 1e5 + 10;
int n, m, a, b;
vector<int> g[nmax];
bool visited[nmax];
int parent[nmax];
int cycle_start = -1, cycle_end  = -1;
 
bool dfs(int s, int p) {
  visited[s] = true;
  parent[s] = p;
  for(int node : g[s]) {
    if(node == p) continue;
    if(visited[node]) {
      cycle_start = s;
      cycle_end = node;
      return true;
    } else {
      if(dfs(node, s)) return true;
    }
  }
  return false;
}
 
void solve() {
  cin >> n >> m;
  rep(i,m) {
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  bool cycle = false;
  for(int i = 1;i <= n;i++) {
    if(!visited[i]) {
      cycle = dfs(i, -1);
      if(cycle) break;
    }
  }
 
  if(!cycle) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> ans;
    while(cycle_start != cycle_end) {
      // cout << "loop" << endl;
      ans.pb(cycle_start);
      cycle_start = parent[cycle_start];
    }
    ans.pb(cycle_start);
    ans.pb(ans[0]);
    cout << ans.size() << endl;
    for(int node : ans) cout << node << " ";
  }
 
}
 
// n    n
// n+1  2*n
// n+2  3*n
// n+3  4*n
 
 
// 0 1, 1 0, 1 1
 
// 100 d=5
 
// 1111811111 d=4
 
// - - - - - - if d is present then good
 
 
// n1*d + n2*10d + n3*100d
// 0 0 0 0 0 d
// 0 0 0 0 d
// 0 0 0 d
// 0 0 d
// 0 d
// d
 
 
int main() {
 
 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);
 // cout << fixed << setprecision(15);2000000000
 
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 // prime_factors();
 int t = 1;
 // cin >> t;
 while (t--) {
   solve();
 }
 
 return 0;
}
