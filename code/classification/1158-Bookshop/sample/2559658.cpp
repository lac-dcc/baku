#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
 
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	vector<int> cost(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	vector<int> value(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	vector<vector<int>> dp(2, vector<int>(x + 1));
	for (int i = 1; i <= n; i++) {
		int t = i % 2;
		for (int j = 1; j <= x; j++) {
			dp[t][j] = dp[!t][j];
			if (j >= cost[i])
				dp[t][j] = max(dp[t][j], dp[!t][j - cost[i]] + value[i]);
		}
	}
	cout << dp[(n % 2)][x];
}
