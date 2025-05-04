/**
 * @author mayavi
 */
 
#define USE_GNU_PBDS
 
#include "bits/stdc++.h"
using namespace std;
 
#ifdef BUILD_LOCAL
#define DBG_MACRO_NO_WARNING
#include "dbg.hpp"
#else
#define dbg(...)
#endif  // BUILD_LOCAL
 
#ifdef USE_GNU_PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T, typename Cmp = less<T>>
using oset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
#endif  // USE_GNU_PBDS
 
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define F_OR(i, start, stop, step) for (auto i=(start); (step)>0?(i)<(stop):(i)>(stop); (i)+=(step))
#define F_OR1(stop) F_OR(i, 0, stop, 1)
#define F_OR2(i, stop) F_OR(i, 0, stop, 1)
#define F_OR3(i, start, stop) F_OR(i, start, stop, 1)
#define F_OR4(i, start, stop, step) F_OR(i, start, stop, step)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: (a))
 
#define endl "\n"
 
#define F first
#define S second
 
#define EPS 1.0e-9
#define MOD 1000000007 // 10^9 + 7
 
// Maximum and Minimum of n elements of **same datatype**
template<typename T>
T nmax(const T& a, const T& b) { return a > b ? a : b; }
template<typename T, typename... Args>
T nmax(const T& a, Args... args) { return nmax(a, nmax(args...)); }
template<typename T>
T nmin(const T& a, const T& b) { return a < b ? a : b; }
template<typename T, typename... Args>
T nmin(const T& a, Args... args) { return nmin(a, nmin(args...)); }
 
const int d4i[] = {-1, 0, 1, 0}, d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};
 
typedef long long       ll;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<ll>      vll;
typedef pair<int, int>  pi;
typedef pair<ll, ll>    pll;
 
#define PER_CASE 0  // call `solve()` per test case
 
void solve() {  /* __start__ */
    int n, m, q; cin >> n >> m >> q;
 
    vector<vll> d(n,vll(n,1e18));
 
    FOR(m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
 
        if (d[u][v] > w) d[u][v] = d[v][u] = w;
    }
 
    FOR(n) d[i][i] = 0;
 
    FOR(k,n) FOR(i,n) FOR(j,n)
        if (d[i][k]+d[k][j] < d[i][j]) d[i][j] = d[j][i] = d[i][k]+d[k][j];
 
    FOR(q) {
        ll u, v; cin >> u >> v;
        u--; v--;
        if (d[u][v] == 1e18) d[u][v] = -1;
        cout << d[u][v] << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if PER_CASE
    dbg("RUNNING SOLUTION PER TEST CASE");
    ll _t;
    cin >> _t;
    while (_t--) {
#endif
    solve();
#if PER_CASE
    }
#endif
}
