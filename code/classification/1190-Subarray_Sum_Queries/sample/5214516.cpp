#include<bits/stdc++.h>
#define ld long double
#define ss second
#define ff first
#define int long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define ll long long
#define rall(x) x.rbegin(), x.rend()
#define sz(a) (int)a.size()
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define sp(x) fixed << setprecision(x)
#define ms multiset
#define pb(x) push_back(x)
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e6 + 5;
const long long inf = 9e18;
const int M = 3e3 + 5;
const double EPS = 1e-6;
const ll neg = -1;
const string imp = "impossible";
void setIO(string name = "") {
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
void boost(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}
const ll MAXN = 200001;
 
struct Node {
	ll g_max, l_max, r_max, sum;
	Node operator +(Node b) {
		return {
			max(max(g_max, b.g_max), r_max + b.l_max),
			max(l_max, sum + b.l_max),
			max(b.r_max, r_max + b.sum),
			sum + b.sum
		};
	}
};
 
ll n, a[MAXN];
Node segtree[4 * MAXN];
 
void build(ll l = 1, ll r = n, ll node = 1) {
	if (l == r) segtree[node] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
	else {
		ll mid = (l + r) / 2;
		build(l, mid, node * 2);
		build(mid + 1, r, node * 2 + 1);
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
}
void update(ll pos, ll val, ll l = 1, ll r = n, ll node = 1) {
	if (l == r) segtree[node] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
	else {
		ll mid = (l + r) / 2;
		if (pos > mid) update(pos, val, mid + 1, r, node * 2 + 1);
		else update(pos, val, l, mid, node * 2);
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
}
void solve(){
	ll q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();
 
	while (q--) {
		ll x, y;
		cin >> x >> y;
		update(x, y);
		cout << segtree[1].g_max << '\n';
	}}
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll q = 1; 
	//cin >> q;
	while(q--) {
		solve();
	}
 
	return 0;
}
 
