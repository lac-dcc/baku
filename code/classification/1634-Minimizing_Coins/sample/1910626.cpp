#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
	ll n, amt;
	cin >> n >> amt;
	ll coins[n];
	for(ll i = 0; i<n; ++i){
		cin >> coins[i];
	}
	ll dp[amt + 1];
	dp[0] = 0;
	for(ll i = 1; i <= amt; ++i){
		dp[i] = INT_MAX;
	}
	for(ll i = 1; i<=amt; ++i){
		for(ll c : coins){
			if(i >= c){
				dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
	}
	if(dp[amt] == INT_MAX){
		cout << -1;
	}else{
	    cout << dp[amt];
    }
 
	return 0;
}
