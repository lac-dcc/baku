#include <iostream>
#include <vector>
 
 
using namespace std;
 
typedef long long ll;
 
int main() {
	const ll mod = 1e9 + 7;	
	
	cin.sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<ll> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
		
	vector<ll> dp(x + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int i2 = 0; i2 <= x; i2++) {
			if (dp[i2] && i2 + c[i] <= x) {
				dp[i2 + c[i]] = (dp[i2 + c[i]] + dp[i2]) % mod;
			}
		}
 
		/*
		for (auto x : dp) 
			cout << x << " ";
		cout << endl;
		*/
	}
 
	cout << dp[x] % mod << endl;
}