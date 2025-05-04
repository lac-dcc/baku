#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forbn(i, b, n) for(int i = b; i < n; ++i)
#define sz(v) (int)v.size()
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
template <class T> inline void mineq(T &a, T b) { a = min(a, b); }
template <class T> inline void maxeq(T &a, T b) { a = max(a, b); }
 
 
struct Seg {
	int n;
	vector<ll> add, mx, t;
	const ll INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
 
	Seg(int n, vector<ll> &vals): n(n) {
		add.resize(4 * n);
		mx.resize(4 * n);
		t.resize(4 * n);
 
		build(vals);
	}
 
	void build(vector<ll> &vals, int v = 1, int tl = 0, int tr = -1) {
		if(tr == -1) tr = n - 1;
 
		if(tl == tr) {
			mx[v] = vals[tl];
			t[v] = vals[tl];
			return;
		}
		int tm = (tl + tr) / 2;
 
		build(vals, 2 * v, tl, tm);
		build(vals, 2 * v + 1, tm + 1, tr);
 
		mx[v] = max(mx[2 * v], mx[2 * v + 1]);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
 
	void propagate(int v, int tl, int tr) {
		if(tl == tr || add[v] == 0)
			return;
 
		int tm = (tl + tr) / 2;
 
		add[2 * v] += add[v];
		add[2 * v + 1] += add[v];
		mx[2 * v] += add[v];
		mx[2 * v + 1] += add[v];
		t[2 * v] += (tm + 1 - tl) * add[v];
		t[2 * v + 1] += (tr - tm) * add[v];
		add[v] = 0;
	}
 
	void update(int l, int r, ll val, int v = 1, int tl = 0, int tr = -1) {
		if(tr == -1) tr = n - 1;
		propagate(v, tl, tr);
		if(l > r) return;
 
		if(tl == l && r == tr) {
			add[v] = val;
			mx[v] += val;
			t[v] += val * (tr + 1 - tl);
			return;
		}
		int tm = (tl + tr) / 2;
 
		update(l, min(r, tm), val, 2 * v, tl, tm);
		update(max(l, tm + 1), r, val, 2 * v + 1, tm + 1, tr);
 
		mx[v] = max(mx[2 * v], mx[2 * v + 1]);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
 
	ll query(int l, int r, int v = 1, int tl = 0, int tr = -1) {
		if(tr == -1) tr = n - 1;
		propagate(v, tl, tr);
		if(l > r) return -INF;
 
		if(tl == l && r == tr)
			return mx[v];
		int tm = (tl + tr) / 2;
 
		ll m1 = query(l, min(r, tm), 2 * v, tl, tm);
		ll m2 = query(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
 
		return max(m1, m2);
	}
 
	ll at(int p, int v = 1, int tl = 0, int tr = -1) {
		if(tr == -1) tr = n - 1;
		propagate(v, tl, tr);
 
		if(tl == tr)
			return mx[v];
		int tm = (tl + tr) / 2;
 
		if(p <= tm)
			return at(p, 2 * v, tl, tm);
		else
			return at(p, 2 * v + 1, tm + 1, tr);
	}
 
	ll real_at(int p) {
		return at(p) - (p ? at(p - 1) : 0);
	}
};
 
 
void solve() {
	int n, q;
	cin >> n >> q;
	vector<ll> vals(n);
	forn(i, n)
		cin >> vals[i];
	forbn(i, 1, n)
		vals[i] += vals[i - 1];
 
	Seg seg(n, vals);
 
	forn(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int k, u;
			cin >> k >> u;
			k--;
			seg.update(k, n - 1, u - seg.real_at(k));
		} else {
			int l, r;
			cin >> l >> r;
			l--; r--;
 
			ll pr = max(0ll, seg.query(l, r) - (l ? seg.at(l - 1) : 0));
 
			cout << pr << '\n';
		}
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
 
//	freopen("snowcow.in", "r", stdin);
//	freopen("snowcow.out", "w", stdout);
 
	int t = 1;
//	cin >> t;
	while(t--) {
		solve();
	}
}
