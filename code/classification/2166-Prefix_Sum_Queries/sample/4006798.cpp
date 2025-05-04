#include <bits/stdc++.h>
 
#define int long long
#define ed '\n'
#define pb push_back
 
using namespace std;
const int maxn = 2e5 + 10 ;
int a[maxn], n, q;
struct dta {
    int pre, sum;
} node[4 * maxn], neutral;
//
struct segtree {
    dta Merge(dta &a, dta &b) {
        if (a.pre > a.sum + b.pre) return {a.pre, a.sum + b.sum} ;
        else return {a.sum + b.pre, a.sum + b.sum} ;
    }
    void build(int x, int lx, int rx) {
        if (lx == rx) {
            node[x] = {a[lx], a[lx]} ;
            return;
        }
        int mid = (lx + rx) >> 1;
        build(2*x+1, lx, mid) ;
        build(2*x+2, mid+1, rx) ;
        node[x] = Merge(node[2*x+1], node[2*x+2]) ;
    }
 
    void upd(int x, int lx, int rx, int id, int val) {
        if (lx == rx) {
            node[x] = {val, val} ;
            return;
        }
        int mid = (lx + rx) >> 1 ;
        if (id <= mid) upd(2*x+1, lx, mid, id, val) ;
        else upd(2*x+2, mid+1, rx, id, val) ;
 
        node[x] = Merge(node[2*x+1], node[2*x+2]) ;
    }
    void upd(int id, int val) {
        upd(0, 1, n, id, val) ;
    }
 
    dta get(int x, int lx, int rx, int l, int r) {
        if (lx > r || rx < l) return neutral ;
        if (l <= lx && rx <= r) return node[x] ;
        int mid = (lx + rx) >> 1 ;
        dta t1 = get(2*x+1, lx, mid, l, r) ;
        dta t2 = get(2*x+2, mid+1, rx, l, r) ;
        return Merge(t1, t2) ;
    }
    int get(int l, int r) {
        return max(get(0, 1, n, l, r).pre, 0LL);
    }
} st;
//
void solve() {
    cin >> n>> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
 
    st.build(0, 1, n) ;
    while(q--) {
        int type, a, b;
        cin >> type >> a>> b;
        if (type == 1) {
            st.upd(a, b) ;
        }
        else {
            cout << st.get(a, b) << ed ;
        }
    }
}
//
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("cf.inp", "r")) {
        freopen("cf.inp", "r", stdin) ;
    }
    solve() ;
    return 0 ;
}
