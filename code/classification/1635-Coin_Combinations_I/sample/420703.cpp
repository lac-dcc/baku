#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int MOD = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	
	vector<int> coins(n);
	for (auto &c : coins) cin >> c;
	
	vector<int> dp(x+1, 0);
	dp[0] = 1;
	
	for (int i=1; i<=x; ++i) {
		for (auto c : coins) {
			if (i - c >= 0)
				(dp[i] += dp[i-c]) %= MOD;
		}
	}
	
	cout << dp[x];
	
	return 0;
}