#include <bits/stdc++.h>
using namespace std;
 
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long int ll;
 
#define int ll
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
 
signed main()
{
	int n,c; cin >> c  >> n;
	vector<int> dp(n+1, 0);
	vector<int> coins(c);
	for(int i=0; i<c; i++) cin >> coins[i];
 
	dp[0] = 1;
	for(int i=1; i<=n; i++)
	{
		for(int j:coins){
			if(i-j < 0) continue;
			dp[i] += dp[i-j];
		}
		dp[i] %= MOD;
	}
	cout << dp[n] << "\n";
}