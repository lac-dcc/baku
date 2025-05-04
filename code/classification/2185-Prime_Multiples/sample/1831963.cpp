#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
ll n, a[20];
int k;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; ++i) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i < (1 << k); ++i) {
		ll cur = n;
		for (int j = 0; j < k; ++j) if (i & (1 << j)) cur /= a[j];
		ans += cur * (__builtin_popcount(i) % 2 ? 1 : -1);
	}
	cout << ans;
	return 0;
}