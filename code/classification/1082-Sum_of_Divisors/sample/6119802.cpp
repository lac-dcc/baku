#include <bits/stdc++.h>

#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;
 
const int MOD = 1e9 + 7;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ll n; cin >> n;
 
	ll sum = 0;
	for (ll i = 1; i * i <= n; ++i) {
		ll x = n / i;
		(sum += (((x - i) % MOD) * ((x + i + 1) % MOD) / 2) + ((i * (x - i + 1)) % MOD)) %= MOD;
	}
	cout << sum;
}