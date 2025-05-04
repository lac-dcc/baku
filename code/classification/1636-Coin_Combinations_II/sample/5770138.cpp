#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 3, M = 1e9 + 7;
int dp[N], ar[102];
 
int main() {
 
	int n, t; scanf("%d%d", &n, &t);
 
	for(int i=1; i<=n; ++i) scanf("%d", &ar[i]);
 
 
	dp[0] = 1;
	for(int i=1; i<=n; ++i) {
		for(int k=1; k<=t; ++k) {
			if(k - ar[i] < 0) continue ;
			dp[k] = (dp[k] + dp[k-ar[i]]) % M;
		}
	}
 
	printf("%d", dp[t]);
	return 0;
}