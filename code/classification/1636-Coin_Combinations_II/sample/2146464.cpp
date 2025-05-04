#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
#define ll long long
 
const ll mod = 1e9 + 7;
 
int main(void) {
	fast ;
 
	ll n, x;
	cin >> n >> x;
 
	ll coins[n];
	for (int i = 0; i < n; ++i) cin >> coins[i];
 
	ll dp[x + 1];
	memset(&dp, 0, sizeof(dp));
	dp[0] = 1;
 
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= x; ++j)
			if (j - coins[i] >= 0) {
				dp[j] += dp[j - coins[i]];
				dp[j] %= mod;
			}
 
	cout << dp[x];
 
	return 0;
}