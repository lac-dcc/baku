#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;
#define ll long long
 
ll solve(ll x, ll coin[], ll n, ll dp[]) {
	dp[0] = 1;
	for (int j = 1; j <= x; j++) {
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (j >= coin[i]) {
				ans = (ans + dp[j - coin[i]]) % 1000000007;
			}
		}
		dp[j] = ans;
	}
	return dp[x];
}
 
 
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ll n;
	cin >> n;
	ll x;
	cin >> x;
	ll coin[n], dp[x + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout << solve(x, coin, n, dp);
 
 
 
	return 0;
}
