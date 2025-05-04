#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;
 
int n, need;
vector<ll> a;
 
struct info {
	ll w;
	int u, v;
	info() {}
	info(ll ww, int uu, int vv) {
		w = ww;
		u = uu;
		v = vv;
	}
	bool operator < (const info &a) const {
		if (w != a.w) return w < a.w;
		if (u != a.u) return u < a.u;
		return v < a.v;
	}
};
 
set<info> I;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> need;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 1; i < n; i++) for (int j = i + 1; j < n; j++)
		I.insert(info(a[i] + a[j], i, j));
	for (int i = 1; i + 2 < n; i++) {
		for (int j = i + 1; j < n; j++)
			I.erase(info(a[i] + a[j], i, j));
		for (int j = 0; j < i; j++) {
			auto it = I.lower_bound(info(need - a[i] - a[j], 0, 0));
			if (it != I.end() && it->w == need - a[i] - a[j]) {
				cout << i + 1 << " " << j + 1 << " " << it->u + 1 << " " << it->v + 1 << '\n';
				return 0;
			}
		}
	}
	finish("IMPOSSIBLE");
}
