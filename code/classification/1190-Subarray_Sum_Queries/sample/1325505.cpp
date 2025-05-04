/* 
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <array>
 
#define x first
#define y second
#define debug(x) cerr << (#x) << ": " << (x) << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int mod = 1e9 + 7, N = 2e5 + 10;
 
struct Node {
	int l, r;
	//sum, left psum, right psum, contiguous sum
	ll sum, lmax, rmax, tmax;
} tr[N << 2];
 
//----------------------------------------------------
int n, m;
ll w[N];
 
void pushup(Node &u, Node &l, Node &r) {
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, l.sum + r.lmax);
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}
 
void pushup(int u) {
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
 
void build(int u, int l, int r) {
	if(l == r) tr[u] = {l, r, w[r], w[r], w[r], w[r]};
	else {
		tr[u] = {l, r};
		int mid = (l + r) >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
 
void modify(int u, int x, int v) {
	if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};
	else {
		int mid = (tr[u].l + tr[u].r) >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}
 
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> w[i];
	build(1, 1, n);
	while(m --) {
		int a, b;
		cin >> a >> b;
		modify(1, a, b);
		cout << max(tr[1].tmax, 0ll) << endl;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --) {
		solve();
	}
 
	return 0;
}
