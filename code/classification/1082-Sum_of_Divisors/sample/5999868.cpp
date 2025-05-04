#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7, inv2 = (mod + 1) / 2;
signed main() {
	int n, ans = 0;
	scanf("%lld\n", &n);
	for (int l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		(ans += (l + r) % mod * ((r - l + 1) % mod) % mod * inv2 % mod * (n / l % mod) % mod) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}