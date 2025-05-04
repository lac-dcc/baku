// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int dp[1500005];
const int MOD = 1e9+7;
int N[105];
int main() {
	int n,x;
	cin >> n >> x;
	for(int i = 0;i<n;i++) cin >> N[i];
	dp[0] = 1;
	for(int i=0;i<n;i++) {
		for(int j = 0;j<=x;j++) {
			if(j-N[i]>=0) {
				dp[j] += dp[j-N[i]];
				dp[j] %= MOD;
			}
		}
	}
	cout << dp[x];
}
 