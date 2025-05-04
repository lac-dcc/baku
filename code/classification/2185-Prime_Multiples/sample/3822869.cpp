#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
ll n, ans;
ll primes[25];
int k;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> primes[i];
 
	bool skip = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		ll prod = 1;
		for (int i = 0; i < k && !skip; i++) {
			if (mask & (1 << i)) {
				if (ld(prod) * primes[i] > n) skip = 1;
				prod *= primes[i];
			}
		}
		if (skip) {
			skip = 0;
			continue;
		}
		ll multiple_count = n / prod;
		// cerr << "// mask : " << bitset<5>(mask) << ", prod : " << prod << ", multiple_count : " << multiple_count << '\n';
 
		if (__builtin_popcount(mask) % 2 == 0) {
			ans -= multiple_count;
		} else {
			ans += multiple_count;
		}
	}
 
	cout << ans << '\n';
}