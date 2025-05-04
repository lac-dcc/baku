#include <bits/stdc++.h>
using namespace std;
 
#define el '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
ll inf = 1e18 + 1ll;
 
struct segtree {
    segtree *left, *right;
    int l, r;
    ll value, lazy;
    ll nullVal = -inf; // 0 for sum, -inf for max, inf for min, etc
 
    segtree(vl &v, int l, int r) : l(l), r(r) {
        int m = (l+r)>>1;
        lazy = 0ll;
        if (l != r) {
            left = new segtree(v, l, m);
            right = new segtree(v, m+1, r);
            value = operation(left->value, right->value);
        } else value = v[l];
    }
 
    ll operation(ll leftValue, ll rightValue) {
        return max(leftValue, rightValue);
    }
 
    void propagate() {
        if (lazy) { // if there's something to propagate
            value += lazy;
            if (l != r) {
                left->lazy += lazy; right->lazy += lazy;
            }
            lazy = 0ll;
        }
    }
 
    ll get(int a, int b, bool p) {
        if (p) cout << l << " " << r;
        propagate(); // Lazy propagation
        if (a > r || b < l) {
            if (p) cout << el;
            return nullVal;
        }
        if (a <= l && b >= r) {
            if (p) cout << " -> " << value << el;;
            return value;
        }
        if (p) cout << el;
        return operation(left->get(a, b, p), right->get(a, b, p));
    }
 
    void update(int a, int b, ll newValue) {
        propagate(); // Lazy propagation
        if (a > r || b < l) return;
        if (a <= l && b >= r) {
            lazy += newValue; // There's propagation
            // value = newValue; // There's not propagations
            propagate();
            return;
        }
 
        left->update(a,b,newValue);
        right->update(a,b,newValue);
 
        value = operation(left->value, right->value);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, q; cin >> n >> q;
    vl v(n+1);
    vl arr(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        arr[i-1] = v[i];
        v[i]+=v[i-1];
    }
 
    segtree tree(v, 0, n);
 
    int o, a, b; ll x;
    while(q--) {
        cin >> o;
        if (o == 1) {
            cin >> a >> x;
            tree.update(a,n,x - arr[a-1]);
            arr[a-1] = x;
        } else {
            cin >> a >> b;
            ll ans = tree.get(a,b, false) - tree.get(a-1, a-1, false);
            cout << max(0ll, ans) << el;
        }
    }
 
    return 0;
}
