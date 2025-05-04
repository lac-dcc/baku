#include<bits/stdc++.h>
using namespace std;
long long dp[1000001];
 
int main(){
    int n, tar;
    cin>>n>>tar;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
 
    dp[0] = 1;
 
    for (int weight = 0; weight <= tar; weight++) {
		for (int i = 1; i <= n; i++) {
			if(weight - coins[i - 1] >= 0) {
				dp[weight] += dp[weight - coins[i - 1]];
				dp[weight] %= 1000000007;
			}
		}
	}
	cout << dp[tar];
 
    return 0;
}
 