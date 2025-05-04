#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
#define vt vector
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
 
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
#define F_OR(i, a, b, s) \
  for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)     \
  F_ORC(__VA_ARGS__) \
  (__VA_ARGS__)
 
#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...)     \
  E_ACHC(__VA_ARGS__) \
  (__VA_ARGS__)
 
#define sim template <class c
#define ris return *this
#define dor > dbg &operator<<
#define eni(x)                                                              \
  sim > typename enable_if<sizeof dud<c>(0) x 1, dbg &>::type operator<<( \
            c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dbg {
#ifdef LOCAL
  ~dbg() { cerr << endl; }
  eni(!=) cerr << boolalpha << i;
  ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c &) { ris; }
#endif
};
 
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
 
/*
DEBUG: -D LOCAL
dbg() << imie(k) imie(x) imie(row) imie(col);
*/
 
const int N = 2e5 + 5;
 
template <typename T>
struct Node {
  T sm, mxPref, mnPref, ans;
};
 
ll n, q, x, A[N];
template <typename T>
struct SegTree {
  Node<T> tree[4 * N];
 
  void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sm = A[l];
      tree[i].mxPref = max(0LL, A[l]);
      tree[i].mnPref = min(0LL, A[l]);
      tree[i].ans = tree[i].mxPref;
      return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i].sm = tree[2 * i].sm + tree[2 * i + 1].sm;
    tree[i].mxPref = max(tree[2*i].mxPref, tree[2*i].sm + tree[2*i+1].mxPref);
    tree[i].mnPref = min(tree[2*i].mnPref, tree[2*i].sm + tree[2*i+1].mnPref);
    tree[i].ans = max({tree[2*i].sm - tree[2*i].mnPref + tree[2*i+1].mxPref,
                        tree[2*i].ans, tree[2*i+1].ans});
  }
 
  void upd(int idx, T x, int i = 1, int l = 1, int r = n) {
    if (l == r) {
      tree[i].sm = x;
      tree[i].mxPref = max(0LL, x);
      tree[i].mnPref = min(0LL, x);
      tree[i].ans = tree[i].mxPref;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m)
      upd(idx, x, i * 2, l, m);
    else
      upd(idx, x, i * 2 + 1, m + 1, r);
    tree[i].sm = tree[i * 2].sm + tree[i * 2 + 1].sm;
    tree[i].mxPref = max(tree[2*i].mxPref, tree[2*i].sm + tree[2*i+1].mxPref);
    tree[i].mnPref = min(tree[2*i].mnPref, tree[2*i].sm + tree[2*i+1].mnPref);
    tree[i].ans = max({tree[2*i].sm - tree[2*i].mnPref + tree[2*i+1].mxPref,
                        tree[2*i].ans, tree[2*i+1].ans});
  }
 
  Node<T> qry(int a, int b, int i = 1, int l = 1, int r = n) {
    if (b < l || a > r) return {0, 0, 0, 0};
    if (a <= l && r <= b) return tree[i];
    int m = (l + r) / 2;
    Node<T> ql = qry(a, b, i * 2, l, m), qr = qry(a, b, i * 2 + 1, m + 1, r), q;
    q.sm = ql.sm + qr.sm;
    q.mxPref = max(ql.mxPref, ql.sm + qr.mxPref);
    q.mnPref = min(ql.mnPref, ql.sm + qr.mnPref);
    q.ans = max({ql.sm - ql.mnPref + qr.mxPref,
                  ql.ans, qr.ans});
    return q;
  }
};
SegTree<ll> seg;
 
int main() {
  fast;
  cin >> n >> q;
  FOR(i, 1, n+1)
    cin >> A[i];
 
  seg.build();
 
  int u;
  while(q--) {
    cin >> u >> x;
    seg.upd(u, x);
    auto qq = seg.qry(1, n);
    cout << qq.ans << en;
  }
}
 
