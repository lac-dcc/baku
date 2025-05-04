#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
 
struct Seg {
    int n;
    vl sum, l, r, mx;
 
    void set(int k, int x) {
        sum[k] = l[k] = r[k] = mx[k] = x;
    }
 
    void merge(int k) {
        sum[k] = sum[2 * k] + sum[2 * k + 1];
        l[k] = max(l[2 * k], sum[2 * k] + l[2 * k + 1]);
        r[k] = max(r[2 * k + 1], sum[2 * k + 1] + r[2 * k]);
        mx[k] = max({mx[2 * k], mx[2 * k + 1], r[2 * k] + l[2 * k + 1]});
    }
 
    Seg(vi A) {
        while (__builtin_popcount((int) A.size()) != 1) A.pb(0);
        n = A.size();
        sum.resize(2*n); l.resize(2*n); r.resize(2*n); mx.resize(2*n);
        for (int i = 0; i < n; ++i) set(i + n, A[i]);
        for (int i = n - 1; i > 0; --i) merge(i);
    }
 
    void upd(int k, int x) {
        set(k += n, x);
        for (int i = k / 2; i > 0; i /= 2) merge(i);
    }
 
    ll qry() {
        return max(0LL, mx[1]);
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vi a(n);
    for (int & x : a) cin >> x;
 
    Seg seg(a);
 
    while (m--) {
        int k, x; cin >> k >> x;
        --k;
        seg.upd(k, x);
        cout << seg.qry() << '\n';
    }
 
    return 0;
}
