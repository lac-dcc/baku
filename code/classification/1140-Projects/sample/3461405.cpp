#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
template <typename T, typename U>
constexpr bool ckmax(T &t, const U u) {
    return u>t ? t=u,true : false;
}
 
struct project {
    int st, en, rw;
    friend bool operator<(const project &p1, const project &p2) {
        return p1.en < p2.en;
    }
};
 
template <int N>
struct Segtree {
    ll a[2*N]; int n;
    void init(int _n) { n = _n; }
    void upd(int p, ll x) {
        for (ckmax(a[p += n], x); p >>= 1; ) {
            a[p] = max(a[2*p], a[2*p+1]);
        }
    }
    ll query(int l, int r) {
        ll s = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) s = max(s, a[l++]);
            if (r&1) s = max(s, a[--r]);
        }
        return s;
    }
};
 
int main() {
    static Segtree<524288> seg;
    static project p[262144];
 
    int n; cin >> n;
    map<int, int> mp; seg.init(2*n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].st >> p[i].en >> p[i].rw;
        mp[p[i].st], mp[p[i].en];
    }
    { int i = 0; for (auto &[_, k] : mp) k = i++; }
    for (int i = 0; i < n; ++i) {
        p[i].st = mp[p[i].st];
        p[i].en = mp[p[i].en];
    }
    sort(p, p+n);
 
    for (int i = 0; i < n; ++i) {
        const auto [st, en, rw] = p[i];
        seg.upd(en, seg.query(0, st) + rw);
    }
    cout << seg.query(0, 2*n) << '\n';
}