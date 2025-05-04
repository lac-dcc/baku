#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int mxN = 2e5;
int n, q;
int h[mxN + 5];
struct node {
    ll sum, mx, mxL, mxR;
};
 
node segtree[4*mxN];
 
void build(int pos = 0, int l = 0, int r = n-1) {
    if (l == r) {
        segtree[pos].sum = segtree[pos].mx = segtree[pos].mxL = segtree[pos].mxR = h[l];
        return;
    }
    int lc = 2*pos+1, rc = 2*pos+2, mid = l+(r-l)/2;
 
    build(lc, l, mid);
    build(rc, mid+1, r);
 
    segtree[pos].sum = segtree[lc].sum + segtree[rc].sum;
    segtree[pos].mx = max({segtree[lc].mx, segtree[rc].mx, segtree[lc].mxR + segtree[rc].mxL});
    segtree[pos].mxL = max(segtree[lc].mxL, segtree[lc].sum + segtree[rc].mxL);
    segtree[pos].mxR = max(segtree[rc].mxR, segtree[rc].sum + segtree[lc].mxR);
}
 
void upd(int id, ll val, int pos = 0, int l = 0, int r = n-1) {
    int lc = 2*pos+1, rc = 2*pos+2, mid = l+(r-l)/2;
    if (r < id || id < l) return;
 
    if (id == l && r == id) {
        segtree[pos].sum = segtree[pos].mx = segtree[pos].mxL = segtree[pos].mxR = val;
        return;
    }
 
    upd(id, val, lc, l, mid);
    upd(id, val, rc, mid+1, r);
 
    segtree[pos].sum = segtree[lc].sum + segtree[rc].sum;
    segtree[pos].mx = max({segtree[lc].mx, segtree[rc].mx, segtree[lc].mxR + segtree[rc].mxL});
    segtree[pos].mxL = max(segtree[lc].mxL, segtree[lc].sum + segtree[rc].mxL);
    segtree[pos].mxR = max(segtree[rc].mxR, segtree[rc].sum + segtree[lc].mxR);
}
 
void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> h[i];
    build();
    for (int i = 0; i < q; i++) {
        int id, val;
        cin >> id >> val;
        --id;
        upd(id, val);
        cout << max(0LL, segtree[0].mx) << '\n';
    }
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    //cin >> tc;
    for(int itc = 1; itc <= tc; itc++){
        //cout << "Case " << itc << ":\n";
        solve();
    }
    return 0;
}
