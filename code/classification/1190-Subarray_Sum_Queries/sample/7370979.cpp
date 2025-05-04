#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
const ll MAXN = 200001;
 
struct Node {
	ll g_max, l_max, r_max, sum;
	Node operator+(Node b) {
		return {max(max(g_max, b.g_max), r_max + b.l_max),
		        max(l_max, sum + b.l_max), max(b.r_max, r_max + b.sum),
		        sum + b.sum};
	}
};
 
ll n, a[MAXN];
Node segtree[4 * MAXN];
 
void build(ll l = 1, ll r = n, ll node = 1) {
	if (l == r)
		segtree[node] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
	else {
		ll mid = (l + r) / 2;
		build(l, mid, node * 2);
		build(mid + 1, r, node * 2 + 1);
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
}
void update(ll pos, ll val, ll l = 1, ll r = n, ll node = 1) {
	if (l == r)
		segtree[node] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
	else {
		ll mid = (l + r) / 2;
		if (pos > mid) update(pos, val, mid + 1, r, node * 2 + 1);
		else update(pos, val, l, mid, node * 2);
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
}
 
int main() {
	ll q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();
 
	while (q--) {
		ll x, y;
		cin >> x >> y;
		update(x, y);
		cout << segtree[1].g_max << '\n';
	}
	return 0;
}
