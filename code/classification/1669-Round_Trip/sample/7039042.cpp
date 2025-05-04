/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 2e9
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define len(x) (x).length()
#define ar array
#define lb lower_bound
#define ub upper_bound
#define tostr to_string
typedef string str; typedef long double ld; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pi; typedef pair<ll, ll> pl; typedef vector<pi> vpi; typedef vector<pl> vpl;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename T1>T amax(T& a, T1 b) {if(b>a)a = b;return a;}
template<typename T, typename T1>T amin(T& a, T1 b) {if(b<a)a = b;return a;}
#ifdef ONPC
#include "/home/pouya/cp.cpp"
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(...)
#define arrdebug(...)
#define LINE
#define TIME
#define nl "\n"
#endif
/*******************************************************************************/
 
const int N = 1e5+10;
int n, m;
bool vis[N];
vi g[N];
vi v;
 
bool dfs(int s, int c) {
  vis[s] = true;
  v.pb(s);
  for (int u: g[s]) {
    if (!vis[u]) {
      if (dfs(u, s)) return true;
    } else {
      if (u!=c) {
        v.pb(u);
        debug(v);
        return true;
      }
    }
  }
  v.ppb();
  return false;
}
void solve() {
  cin >> n >> m;
  for (int i=0, a, b; i<m; i++) {
    cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  bool found = false;
  for (int i=0; i<n; i++) {
    if (!vis[i] and dfs(i, -1)) {
      found = true;
      break;
    }
  }
  if (!found)
    cout << "IMPOSSIBLE" << nl;
  else {
    int c = 2;
    for (int i=sz(v)-2; i>=0 and v[i]!=v[sz(v)-1]; i--) {
      c++;
    }
    cout << c << nl;
    for (int i=0; i<c; i++) {
      cout << v[sz(v)-i-1]+1 << ' ';
    } cout << nl;
    /*
    */
  }
}
 
int main() {
  fastio();
	int T = 1;
	//cin >> T;
	while (T--) {
        solve();
        LINE
	}
    TIME
    return 0;
}
 
 
