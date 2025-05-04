#include <bits/extc++.h>
using namespace std;
 
typedef long long ll;
 
int manhatdist(ll a, ll b, ll x, ll y) {
	return abs(a-x) + abs(b-y);
}
 
int main() {
	ll n; cin >> n;
	while (n--) {
		ll y, x;
		cin >> y >> x;
		ll a = max(x, y), b = min(x, y);
		ll ans = a * a;
		if (a % 2 == 1)
			ans -= manhatdist(1, a, y, x);
		else
			ans -= manhatdist(a, 1, y, x);
		cout << ans << '\n';
	}
	return 0;
}
