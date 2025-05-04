#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll dp[1000001];
 
const int MOD = (int) 1e9 + 7;
 
int main(){
	int n, x; cin >> n >> x;
 
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
 
	dp[0] = 1;
	for (int weight = 0; weight <= x; weight++) {
		for (int i = 0; i < n; i++) {
			if(weight - coins[i] >= 0) {
				dp[weight] += dp[weight - coins[i]];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';
}