#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const ll maxVal = 1e18;
 
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct ST_Node {
    ll s, m;
    ll lazy_s, lazy_m;
 
    ST_Node(ll _s = 0, ll _m = 0, ll _lazy_s = 0, ll _lazy_m = 0)
    : s(_s), m(_m), lazy_s(_lazy_s), lazy_m(_lazy_m) {
    }
 
    bool operator<(const ST_Node& other) const & {
        return m < other.m;
    }
};
 
ST_Node combine_st(const ST_Node& a,const ST_Node& b) {
    return ST_Node(a.s + b.s, max(a.m, b.m), 0, 0);
}
 
int n;
ll a[maxN];
 
ST_Node st[maxN*4];
 
 
void apply_st(int i, ll val_s, ll val_m) {
    st[i].s += val_s;
    st[i].m += val_m;
    st[i].lazy_s += val_s;
    st[i].lazy_m += val_m;
}
 
void down_st(int i) {
    apply_st(2*i, st[i].lazy_s, st[i].lazy_m);
    apply_st(2*i + 1, st[i].lazy_s, st[i].lazy_m);
    st[i].lazy_s = st[i].lazy_m = 0;
}
 
void update_st(int u, int v, ll val_s, ll val_m, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return;
 
    if (u <= l && r <= v) {
        apply_st(i, val_s, val_m);
        return;
    }
 
    int m = (l + r)/2;
    down_st(i);
    update_st(u, v, val_s, val_m, 2*i, l, m);
    update_st(u, v, val_s, val_m, 2*i + 1, m + 1, r);
 
    st[i].s = st[2*i].s + st[2*i + 1].s;
    st[i].m = max(st[2*i].m, st[2*i + 1].m);
}
 
ST_Node get_st(int u, int v, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return ST_Node(0, -maxVal, 0, 0);
 
    if (u <= l && r <= v) 
        return st[i];
 
    int m = (l + r)/2;
    down_st(i);
    auto res = combine_st(get_st(u, v, 2*i, l, m), get_st(u, v, 2*i + 1, m + 1, r));
 
    st[i].s = st[2*i].s + st[2*i + 1].s;
    st[i].m = max(st[2*i].m, st[2*i + 1].m);
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        update_st(i, i, a[i], 0);
        update_st(i, n - 1, 0, a[i]);
    }
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            ll u;
            cin >> k >> u;
            update_st(k - 1, k - 1, u - a[k - 1], 0);
            update_st(k - 1, n - 1, 0, u - a[k - 1]);
            a[k - 1] = u;
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << max(0ll, get_st(l - 1, r - 1).m - get_st(0, l - 2).s) << '\n';
        }
    }
}
