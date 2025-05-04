#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int long long
#define endl "\n"
#define INF 1000000001
 
using namespace std;
 
signed main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<int> dp(k + 1, INF);
	for (int i = 0;i < n;i++)
	{
		cin >> v[i];
	}
	dp[0] = 0;
	for (int i = 1;i <= k;i++)
	{
		for (auto coin : v)
		{
			if (i - coin < 0) continue;
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
	if (dp[k] == INF)
	{
		cout << -1 << endl;
	} else
	cout << dp[k] << endl;
}