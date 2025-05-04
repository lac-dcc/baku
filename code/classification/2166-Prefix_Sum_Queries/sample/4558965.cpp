#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
struct SegmentTree {
    const ll NONE = LLONG_MIN;
    int n;
    vector<ll> st, lz;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
        lz.assign(4 * n + 1, 0);
    }
    SegmentTree(const vector<ll> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    ll merge(const ll &a, const ll &b) const {
        return max(a, b);
    }
    void build(int id, int l, int r, const vector<ll> &a) {
        if (l == r) {
            st[id] = a[l];
        } else {
            int m = (l + r) / 2;
            build(id * 2 + 1, l, m, a);
            build(id * 2 + 2, m + 1, r, a);
            st[id] = merge(st[id * 2 + 1], st[id * 2 + 2]);
        }
    }
    void down(int id, int l, int r) {
        if (l != r) {
            lz[2 * id + 1] += lz[id];
            lz[2 * id + 2] += lz[id];
            st[2 * id + 1] += lz[id];
            st[2 * id + 2] += lz[id];
        }
        lz[id] = 0;
    }
    void update(int id, int l, int r, int fr, int to, int delta) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            st[id] += 1ll*delta;
            lz[id] += 1ll*delta;
            return;
        }
        if (lz[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        update(2 * id + 1, l, m, fr, to, delta);
        update(2 * id + 2, m + 1, r, fr, to, delta);
        st[id] = merge(st[2 * id + 1], st[2 * id + 2]);
    }
    void update(int fr, int to, int val) {
        update(0, 0, n - 1, fr, to, val);
    }
    ll query(int id, int l, int r, int fr, int to) {
        if (r < fr || to < l)
            return NONE;
        if (fr <= l && r <= to)
            return st[id];
        if (lz[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        return merge(
            query(2 * id + 1, l, m, fr, to),
            query(2 * id + 2, m + 1, r, fr, to)
        );
    }
    ll query(int fr, int to) {
        return query(0, 0, n - 1, fr, to);
    }
};
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];
    SegmentTree st(prefix);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            st.update(k, n, u - a[k - 1]);
            a[k - 1] = u;
        } else {
            int l, r;
            cin >> l >> r;
            cout << max(0ll, st.query(l, r) - st.query(l - 1, l - 1)) << endl;
        }
    }
    return 0;
}
