#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int mod = 1e9+7;
 
int sum(int x) {
	return (x*(x+1)/2) % mod;
}
 
int sum1(int y) {
	if (y % 2 == 0) {
		return ((y/2)%mod)*((y+1)%mod) % mod;
	}
	else {
		return (y%mod)*(((y+1)/2) % mod) % mod;
	}
}
 
signed main() {
	int n;
	cin >> n;
	
	int ans = 0;
	for (int i = 1; i <= n/i; i++) {
		ans += (i%mod)*(n/i);
		ans %= mod;
	}
	
	int l, r = n;
	for (int i = 1; i < n/i; i++) {
		l = (n/(i+1))+1;
		if ((i >= sqrt(n)-10) && (sum(r) - sum(l-1)) <= n/((sum(r) - sum(l-1)))) continue;
		int a = (sum1(r) - sum1(l-1)) % mod;
		a = (a+mod) % mod;
		ans += a*(i%mod);
		ans %= mod;
		r = l-1;
	}
	cout << ans << endl;
}
