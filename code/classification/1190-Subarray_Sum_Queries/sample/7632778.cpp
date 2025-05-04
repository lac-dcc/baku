#include "bits/stdc++.h"
using namespace std;
#define int long long
#define mid ((tl + tr) >> 1)
#define lc (node + 1)
#define rc (node + 2 * (mid - tl + 1))
struct Node {
    int pref, suf, sum, seg;
};
struct SegmentTree {
    int n;
    vector<int> arr;
    vector<Node> tree;
    SegmentTree(vector<int>& v) {
        arr = v;
        n = (int) v.size();
        tree.resize(2 * n);
        build(0, n - 1, 1);
    }
    Node merge(Node left, Node right) {
        Node ret{};
        ret.sum = left.sum + right.sum;
        ret.pref = max({left.pref, left.sum + right.pref});
        ret.suf = max({right.suf, right.sum + left.suf});
        ret.seg = max({left.seg, right.seg, left.suf + right.pref});
        return ret;
    }
    void build(int tl, int tr, int node) {
        if (tl == tr) {
            int k = max(0LL, arr[tl]); tree[node] = {k, k, arr[tl], k};
        } else {
            build(tl, mid, lc); build(mid + 1, tr, rc); tree[node] = merge(tree[lc], tree[rc]);
        }
    }
    void update(int tl, int tr, int node, int idx, int val) {
        if (tl > idx || tr < idx) return;
        if (tl == tr) {
            int k = max(0LL, val); tree[node] = {k, k, val, k}; return;
        }
        update(tl, mid, lc, idx, val); update(mid + 1, tr, rc, idx, val);
        tree[node] = merge(tree[lc], tree[rc]);
    }
    int query() { return tree[1].seg; }
};
signed main() {
    int n, q; cin >> n >> q;
    vector<int> v(n); for (auto& i : v) cin >> i;
    SegmentTree st(v);
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        st.update(0, n - 1, 1, idx - 1, val);
        cout << st.query() << '\n';
    }
}
