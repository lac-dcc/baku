 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
const ll INF = 1e9 + 1;
vector<ll> seg, sseg, sz,a;
vector<pair<ll, ll>> range;
ll qw(ll i, ll j) {
	ll ans = 0;
	for (i += n, j += n; i < j; i /= 2, j /= 2) {
		if (i % 2) {
			ans += seg[i++];
		}
		if (j % 2) {
			ans += seg[--j];
		}
	}
	return ans;
}
ll up(ll l, ll r, ll i) {
	ll ans = 0;
	if (l == range[i].first && r == range[i].second) {
		return sseg[i];
	}
	ll mid = (range[i].first + range[i].second - 1) / 2;
	if (l <= mid) {
		ans = max(ans, up(l, min(r, mid + 1), 2 * i));
	}
	if (r > mid + 1) {
		ans = max(ans, qw(l, max(l, mid + 1)) + up(max(l, mid + 1), r, 2 * i + 1));
	}
	return ans;
}
 
void rup(ll i, ll x) {
	i += n;
	seg[i] = x;
	sseg[i] = max(x, 0ll);
	while (i > 1) {
		i /= 2;
		seg[i] = seg[2 * i] + seg[2 * i + 1];
		sseg[i] = max(sseg[2 * i], seg[2 * i] + sseg[2 * i + 1]);
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll m, msz = 1; cin >> n >> m;
	while (msz < n) {
		msz *= 2;
	}
	a=vector<ll>(msz);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	n = msz;
	seg = vector<ll>(2 * n);
	sz = vector<ll>(2 * n);
	range = vector<pair<ll, ll>>(2 * n);
	sseg = vector<ll>(2 * n);
	ll s = 0;
	for (ll i = 0; i < n; i++) {
		ll uti = a[i];
		sseg[i + n] = max(0ll, uti);
		seg[i + n] = uti;
		sz[i + n] = 1;
		range[i + n] = { i,i + 1 };
 
	}
	for (ll i = n - 1; i > 0; i--) {
		sseg[i] = max(sseg[2 * i], seg[2 * i] + sseg[2 * i + 1]);
		seg[i] = seg[2 * i] + seg[2 * i + 1];
		sz[i] = 2 * sz[2 * i];
		range[i] = { range[2 * i].first,range[2 * i + 1].second };
	}
 
	for (ll i = 0; i < m; i++) {
		ll k1, k2, k3; cin >> k1 >> k2 >> k3;
		if (k1 == 1) {
			k2--;
			rup(k2, k3);
		}
		else {
			k2--, k3--;
			cout << up(k2, k3 + 1, 1) << '\n';
		}
	}
}
