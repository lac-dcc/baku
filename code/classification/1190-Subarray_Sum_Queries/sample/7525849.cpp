#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;
#define pb  push_back
#define pf  push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
const ll mod = 1e9 + 7;
const int N = 1e5;
const ll INF = 1e18;
 
struct Node {
	ll g_max, l_max, r_max, sum;
	Node operator+(Node b) {
		return {max(max(g_max, b.g_max), r_max + b.l_max),
		        max(l_max, sum + b.l_max), max(b.r_max, r_max + b.sum),
		        sum + b.sum};
	}
};
 
int sz = 1;
 
struct segtree{
	vector<Node> tree;
	void init(int n){
		while(sz < n) sz *= 2;
		tree = vector<Node>(2*sz-1, {0, 0, 0, 0});
	}
	void set(ll i, ll val, ll x = 0, ll lx = 0, ll rx = sz){
		if(rx - lx == 1){
			tree[x] = {max(0LL, val), max(0LL, val), max(0LL, val), val};
			return;
		}
		ll m = (lx + rx)/2;
		if(i < m){
			set(i, val, 2*x+1, lx, m);
		}
		else{
			set(i, val, 2*x+2, m, rx);
		}
		tree[x] = tree[2*x+1] + tree[2*x+2];
	}
	ll mx(){
		return tree[0].g_max;
	}
};
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n, q; cin >> n >> q;
	segtree st;
	st.init(n);
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		st.set(i, x);
	}
	while(q--){
		ll x, y; cin >> x >> y;
		x--;
		st.set(x, y);
		cout << st.mx() << '\n';
	}
	return 0;
}
