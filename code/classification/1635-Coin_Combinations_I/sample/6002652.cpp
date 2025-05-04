#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int c = 1001, cc = 1000001, mod = 1e9 + 7;
int n, x, a[c], dp[cc];
 
signed main() {
	cin >> n >> x;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp[0] = 1;
	for(int i = 1; i <= x; ++i) {
		for(int j = 0; j < n; ++j) {
			if(a[j] <= i) 
				dp[i] = (dp[i] + dp[i - a[j]]) % mod;
		}
	}
	cout << dp[x] % mod << endl;
}