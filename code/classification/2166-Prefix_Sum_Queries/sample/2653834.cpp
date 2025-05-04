#include "bits/stdc++.h"
 
using namespace std;
 
using vd = void;
using ii = int;
using ll = long long;
 
#define tcT template <class T
 
tcT> using vt = vector<T>;
 
#define pb push_back
 
#define rt return
 
#define fr(i, a, b) for (ii (i) = (a); (i) < (b); ++(i))
#define ff(i, n) fr(i, 0, n)
 
#define fe(a, v) for (auto& (a) : (v))
 
#define sz(v) int( (v).size() )
 
tcT> constexpr T bs(T x) { rt (T)( 63 - __builtin_clzll( (ll)x ) ); }
tcT> constexpr T m2n(T x) { rt (T)bs(x) + ( (x & (x - 1)) > 0 ); }
 
tcT> struct InfoTree {
 
  struct Info { T sum, pre, suf, ans; };
 
  ii n{};
  vt<T> orig;
  vt<Info> tree;
 
  static ii L(ii cr) { rt 2 * cr; }
  static ii R(ii cr) { rt 2 * cr + 1; }
 
  static Info DITTO(T val) {
    Info res{};
    res.sum = val, res.pre = res.suf = res.ans = max(0LL, val);
    rt res;
  }
 
  static Info mix(Info a, Info b) {
    Info res{};
    res.sum = a.sum + b.sum;
    res.pre = max(a.pre, a.sum + b.pre);
    res.suf = max(b.suf, a.suf + b.sum);
    res.ans = max({a.ans, b.ans, a.suf + b.pre});
    rt res;
  }
 
  vd build(ii cr, ii l, ii r) {
    if (l == r) {
      tree[cr] = DITTO(orig[l]);
    } else {
      ii m = (l + r) / 2;
      build(L(cr), l, m);
      build(R(cr), m + 1, r);
      tree[cr] = mix(tree[L(cr)], tree[R(cr)]);
    }
  }
 
  vd upd(ii i, T val, ii cr, ii l, ii r) {
    if (l == r) {
      tree[cr] = DITTO(val);
    } else {
      ii m = (l + r) / 2;
      if (i <= m) {
        upd(i, val, L(cr), l, m);
      } else {
        upd(i, val, R(cr), m + 1, r);
      }
      tree[cr] = mix(tree[L(cr)], tree[R(cr)]);
    }
  }
 
  Info rq(ii i, ii j, ii cr, ii l, ii r) {
    if (i > j) {
      rt DITTO(0);
    }
    if (i <= l && r <= j) {
      rt tree[cr];
    } else {
      ii m = (l + r) / 2;
      rt mix(rq(i, min(m, j), L(cr), l, m), rq(max(i, m + 1), j, R(cr), m + 1, r));
    }
  }
 
  explicit InfoTree(ii n) : n(n), tree(2 * n) {}
 
  InfoTree(ii _n, const vt<T>& v) : InfoTree(1 << m2n(_n)) {
    orig = v;
    while (sz(orig) < n) {
      orig.pb(0);
    }
    build(1, 0, n - 1);
  }
 
  vd upd(ii i, T val) {
    upd(i, val, 1, 0, n - 1);
  }
 
  T rq(ii i, ii j) {
    rt rq(i, j, 1, 0, n - 1).pre;
  }
 
};
 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ii n, q;
  cin >> n >> q;
  vt<ll> v(n);
  fe (a, v) {
    cin >> a;
  }
  InfoTree tree(n, v);
  ff (i, q) {
    ii type;
    cin >> type;
    if (type == 1) {
      ii k;
      ll u;
      cin >> k >> u;
      --k;
      tree.upd(k, u);
    } else {
      ii a, b;
      cin >> a >> b;
      --a, --b;
      cout << tree.rq(a, b) << '\n';
    }
  }
}
