#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'
 
const int INF = 1e18;
 
struct SegmentTree{
	using T = array<int, 4>;
	vector<T> a; // best, prefix, suffix, total
	int sz = 1; const T ID = {0, 0, 0, 0};
	T f(T &x, T &y){
		return {
			max(x[2] + y[1], max(x[0], y[0])),
			max(x[1], x[3] + y[1]),
			max(y[2], y[3] + x[2]),
			x[3] + y[3]
		};
	}
	SegmentTree(vector<int> &v){
		while(sz < (int)v.size()) sz += sz;
		a.assign(2*sz, ID);
		build(v, 0, 0, sz);
	}
	void build(vector<int> &v, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx < (int)v.size()){
				a[x][3] = v[lx];
				a[x][0] = a[x][1] = a[x][2] = max(0LL, v[lx]);
			}
			return;
		}
		int mx = (lx+rx)/2;
		build(v, 2*x+1, lx, mx);
		build(v, 2*x+2, mx, rx);
		a[x] = f(a[2*x+1], a[2*x+2]);
	}
	void update(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			a[x][3] = v;
			a[x][0] = a[x][1] = a[x][2] = max(0LL, v);
			return;
		}
		int mx = (lx+rx)/2;
		if(i<mx) update(i, v, 2*x+1, lx, mx);
		else update(i, v, 2*x+2, mx, rx);
		a[x] = f(a[2*x+1], a[2*x+2]);
	}
	int query(int i, int v){
		update(i, v, 0, 0, sz);
		return a[0][0];
	}
};
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q, k, x; cin >> n >> q;
	vector<int> a(n); for(int &i : a) cin >> i;
 
	SegmentTree st(a);
 
	while(q--){
		cin >> k >> x;
		cout << st.query(k-1, x) nl;
	}
}
