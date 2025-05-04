#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
 
	ll ans = 0;
	for (ll i = 1; i < (1 << k); i++) {
		ll prime_product = 1;
		for (ll j = 0; j < k; j++) {
			// check if we are using a[j] in this number
			if (i & (1 << j)) {
				// check to not overflow, if we do set prime_product to N+1 so
				// ans doesn't change
				if (prime_product > n / a[j]) {
					prime_product = n + 1;
					break;
				}
				prime_product *= a[j];
			}
		}
 
		//__builtin_popcount gives the number of 1's in binary representation,
		// which is also the number of primes we have multiplied
		if (__builtin_popcount(i) % 2) {
			ans += n / prime_product;
		} else {
			ans -= n / prime_product;
		}
	}
 
	cout << ans << endl;
}