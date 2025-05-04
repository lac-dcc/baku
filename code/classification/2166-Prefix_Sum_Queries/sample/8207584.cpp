#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
#define forn(i, n) for(int i=0; i<(int)n; ++i)
#define forsn(i, s, n) for(int i=s; i<(int)n; ++i)
#define dforn(i, n) for(int i=(int)n-1; i>=0; --i)
#define dforsn(i, s, n) for(int i=(int)n-1; i>=s; --i)
 
const int MAXN = 200010;
int n, q, he, arr[MAXN];
ll tr[2*MAXN], lazy[MAXN];
 
void apply(int p, ll value) {
    if(p<n) lazy[p] += value;
    tr[p] += value;
}
 
void push(int p) {
    for(int s=he; s>0; --s) {
        int i = p>>s;
        if(lazy[i]) {
            apply(i<<1, lazy[i]);
            apply(i<<1|1, lazy[i]);
            lazy[i] = 0;
        }
    }
}
 
void build(int p) {
    while(p>1) p>>=1, tr[p] = lazy[p] + max(tr[p<<1], tr[p<<1|1]);
}
 
void inc(int l, int r, ll delta) {
    l+=n, r+=n;
    int l0 = l, r0 = r;
    for(; l<r; l>>=1, r>>=1) {
        if(l&1) apply(l++, delta);
        if(r&1) apply(--r, delta);
    }
    build(l0);
    build(r0-1);
}
 
ll query(int l, int r) {
    ll ans = -1000000000000000000;
    if(l == -1) l=0, ans = 0;
    l+=n, r+=n;
    push(l);
    push(r-1);
    for(; l<r; l>>=1, r>>=1) {
        if(l&1) ans = max(ans, tr[l++]);
        if(r&1) ans = max(tr[--r], ans);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    he = 8*sizeof(int) - __builtin_clz(n);
    forn(i, n) {cin >> arr[i]; inc(i, n, arr[i]);}
    forn(i, q) {
        int t, a, b; cin >> t >> a >> b; --a;
        if(t == 1) inc(a, n, b-arr[a]), arr[a]=b;
        else cout << query(a-1, b) - query(a-1, a) << '\n';
    }
}
