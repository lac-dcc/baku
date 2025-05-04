#include <bits/stdc++.h>
 
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
using ll = long long;
#define int ll
#define all(a) a.begin(), a.end()
 
void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
 
const int NEUT = 0;
 
template <typename T>
struct segtree {
	int n;
	vector<T> seg, lazy;
 
	T build(int p, int l, int r, vector<T> &v) {
		lazy[p] = 0;
		if(l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p,l,m,v), build(2*p+1,m+1,r,v));
	}
 
	segtree(vector<T> &v) : n(v.size()), seg(4*n), lazy(4*n) { build(1,0,n-1,v); }
	segtree(int n) : n(n), seg(4*n), lazy(4*n) {}
 
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if(l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = NEUT;
	}
 
	T update(int a, int b, int x, int p, int l, int r) {
		prop(p,l,r);
		if(b < l or r < a) return seg[p];
		if(a <= l and r <= b) {
			lazy[p] += x;
			prop(p,l,r);
			return seg[p];
		}
		int m=(l+r)/2;
		return seg[p] = max(update(a,b,x,2*p,l,m), update(a,b,x,2*p+1,m+1,r));
	}
 
	T query(int a, int b, int p, int l, int r){
		prop(p,l,r);
		if(a <= l and r <= b) return seg[p];
		if(b < l or r < a) return -1e15;
		int m = (l+r)/2;
		return max(query(a,b,2*p,l,m), query(a,b,2*p+1,m+1,r));
	}
 
	void update(int l, int r, int x) { update(l,r,x,1,0,n-1); }
	T query(int l, int r) { return query(l,r,1,0,n-1); }
};
 
signed main() {
	fastio;
	int n, q; cin>>n>>q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin>>a[i];
 
	vector<int> acum(n+1);
	for (int i = 1; i <= n; i++) acum[i] = acum[i-1] + a[i-1];
 
	segtree<ll> seg(acum);
	for (int i = 0; i < q; i++) {
		int t, l, r; cin>>t>>l>>r;
		if (t == 1) {
			seg.update(l, n, r - a[l-1]);
			a[l-1] = r;
		}
		else {
			cout<<max(0ll, seg.query(l,r) - seg.query(l-1, l-1))<<endl;
		}
	}
 
	return 0;
}
