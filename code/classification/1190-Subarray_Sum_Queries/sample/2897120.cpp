//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;
 
template<class node>
struct segment_tree {
	int n;
	vector<node> t;
	segment_tree(int n) : n(n), t(4 << __lg(n)) {}
	segment_tree(vector<node> init) : segment_tree(init.size()) {
		function<void(int, int, int)> build = [&](int u, int l, int r) {
			if (l == r) {
				t[u] = init[l];
				return;
			}
			int m = (l + r) / 2;
			build(2 * u, l, m);
			build(2 * u + 1, m + 1, r);
			t[u] = t[2 * u] + t[2 * u + 1];
		};
		build(1, 0, n - 1);
	}
	void modify(int u, int l, int r, int x, const node &p) {
		if (l == r) {
			t[u] = p;
			return;
		}
		int m = (l + r) / 2;
		if (x <= m)
			modify(2 * u, l, m, x, p);
		else
			modify(2 * u + 1, m + 1, r, x, p);
		t[u] = t[2 * u] + t[2 * u + 1];
	}
	void modify(int x, const node &p) {
		modify(1, 0, n - 1, x, p);
	}
	node query(int u, int l, int r, int x, int y) {
		if (y < l || r < x)
			return node();
		if (x <= l && r <= y) 
			return t[u];
		int m = (l + r) / 2;
		return query(2 * u, l, m, x, y) + query(2 * u + 1, m + 1, r, x, y);
	}
	node query(int x, int y) {
		return query(1, 0, n - 1, x, y);
	}
}; 
 
struct node {
	ll res, s, l, r;
	friend node operator+ (node a, node b) {
		node c;
		c.res = max({a.res, b.res, a.r + b.l});
		c.s = a.s + b.s;
		c.l = max(a.l, a.s + b.l);
		c.r = max(b.r, b.s + a.r);
		return c;
	}
};
 
int n, q;
 
node f(ll x) {
	ll y = max(0ll, x);
	return node{y, x, y, y};
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	cin >> n >> q;
	vector<node> a(n);
	FOR(i, n) {
		int x;
		cin >> x;
		a[i] = f(x);
	}
	segment_tree<node> T(a);
 
	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;
		T.modify(p, f(x));
		cout << T.t[1].res << '\n';
	}
	return 0;
}
