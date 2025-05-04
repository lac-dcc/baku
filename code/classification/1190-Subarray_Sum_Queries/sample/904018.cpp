#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#define int long long
#define pb push_back
#define x first
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}
const int INF = 1e9, MOD = 1e9 + 7; /// think
const ll LINF = 1e18;
 
 
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
inline bool inside (int x, int y, int n, int m) {
    return 0 <= x && 0 <= y && x < n && y < m;
}
 
template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }
template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }
 
inline void add (int &a, int x) {
    a += x;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}
 
struct node {
    ll ans, sum, pref, suff;
    node (int x) : ans(x), sum(x), pref(x), suff(x) {}
    node (ll ans = 0, ll sum = 0, ll pref = 0, ll suff = 0) : ans(ans), sum(sum), pref(pref), suff(suff) {}
};
vector <node> t;
vector <int> a;
inline node combine (node &a, node &b) {
    return node(max({a.ans, b.ans, a.suff + b.pref}), a.sum + b.sum, max(a.pref, a.sum + b.pref), max(b.suff, b.sum + a.suff));
}
inline void build (int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = node(a[tr]);
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}
inline void upd (int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[v] = node(x);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd (v << 1, tl, tm, pos, x);
    }
    else {
        upd (v << 1 | 1, tm + 1, tr, pos, x);
    }
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}
//inline int go (int v, int tl, int tr, int x) {
//    if (tl == tr) return tr;
//    int tm = (tl + tr) >> 1;
//    if (t[v << 1] >= x) return go(v << 1, tl, tm, x);
//    return go(v << 1 | 1, tm + 1, tr, x - t[v << 1]);
//}
 
//vector <int> t;
//inline void upd (int i, int x) {
//    for (; i < sz(t); i = i | (i + 1)) t[i] += x;
//}
//inline int sum (int r) {
//    int ans = 0;
//    for (; r >= 0; r = (r & (r + 1)) - 1) ans += t[r];
//    return ans;
//}
//inline int sum (int l, int r) {
//    if (l > r) rr;
//    return sum(r) - sum(l - 1);
//}
 
int main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a) cin >> i;
    int l, r;
    t.resize(4 * n);
    build(1, 0, n - 1);
    while (m--) {
        cin >> l >> r;
        --l;
        upd(1, 0, n - 1, l, r);
        cout << max(0ll, t[1].ans) << '\n';
    }
  return 0;
}
