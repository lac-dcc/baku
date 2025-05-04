#include"bits/stdc++.h"
 
using namespace std;
 
#define ll long long
 
struct node {
    ll sum, pref;
 
    node(ll sum, ll pref) : sum(sum), pref(pref) {}
 
    explicit node(ll x = 0) : sum(x), pref(max(0LL, x)) {}
 
    node operator+(const node &other) const {
        return {sum + other.sum, max(pref, sum + other.pref)};
    }
};
 
int n;
vector<ll> arr;
vector<node> tree;
 
void build(int l = 1, int r = n, int i = 1) {
    if (l == r) {
        tree[i] = node(arr[l]);
    } else {
        int mid = (l + r) / 2;
        build(l, mid, 2 * i);
        build(mid + 1, r, 2 * i + 1);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}
 
void update(int pos, ll val, int l = 1, int r = n, int i = 1) {
    if (l == r) {
        tree[i] = node(val);
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) update(pos, val, l, mid, 2 * i);
        else update(pos, val, mid + 1, r, 2 * i + 1);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}
 
node query(int L, int R, int l = 1, int r = n, int i = 1) {
    if (L > R) return node();
    if (L == l && R == r) return tree[i];
    int mid = (l + r) / 2;
    return query(L, min(mid, R), l, mid, 2 * i) +
           query(max(L, mid + 1), R, mid + 1, r, 2 * i + 1);
}
 
int main() {
    int q;
    cin >> n >> q;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
 
    int len = pow(2, ceil(log2(n)));
    tree.resize(2 * len);
    build();
 
    while (q--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 1) {
            update(a, b);
        } else {
            ll ans = query(a, b).pref;
            cout << ans << endl;
        }
    }
}
