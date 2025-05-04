#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5 + 5;
int a[N], n;
 
struct node {
    ll sum, pref, suf, mx;
    node(ll x = 0): sum(x), pref(max(0ll, x)), suf(max(0ll, x)), mx(max(0ll, x)) {};
    node(ll sum, ll pref, ll suf, ll mx): sum(sum), pref(pref), suf(suf), mx(mx) {};
    friend node operator + (const node &a, const node &b) {
        return {
            a.sum + b.sum,
            max(a.pref, b.pref + a.sum),
            max(b.suf, a.suf + b.sum),
            max({a.mx, b.mx, a.suf + b.pref})
        };
    }
} t[1 << 19];
 
 
void build(int k = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        t[k] = a[l];
        return;
    }
 
    int m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
 
    t[k] = t[k << 1] + t[k << 1 | 1];
}
 
void upd(int pos, int val, int k = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        t[k] = val;
        return;
    }
 
    int m = (l + r) >> 1;
    if (pos <= m) upd(pos, val, k << 1, l, m);
    else upd(pos, val, k << 1 | 1, m + 1, r);
 
    t[k] = t[k << 1] + t[k << 1 | 1];
}
 
node qry(int ql, int qr, int k = 1, int l = 0, int r = n - 1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return t[k];
 
    int m = (l + r) >> 1;
    return qry(ql, qr, k << 1, l, m) + qry(ql, qr, k << 1 | 1, m + 1, r);
}
 
void solve() {
    int q;
    cin >> n >> q;
 
    for (int i = 0; i < n; ++i) cin >> a[i];
    build();
 
    while (q--) {
        int k, x;
        cin >> k >> x;
 
        upd(--k, a[k] = x);
        cout << qry(0, n - 1).mx << '\n';
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int tt = 1;
    // cin >> tt;
 
    while (tt--) {
        solve();
    }
 
    return 0;
}
 
// boi vi se co ngay em thay
// nhung chuyen buon hom ay
// chi la chuyen cuoi hom nay
