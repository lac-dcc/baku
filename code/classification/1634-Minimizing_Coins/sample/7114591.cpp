#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
}
int n,x;
int const N = 1e6 + 5;
int dp[N];
int arr[1001];
int const mod = 1e9 + 7;
int solve(int hav)
{
	if (hav == 0)
		return 0;
	if (hav < 0)
		return 1e9;
	int &ret = dp[hav];
	if (ret + 1)
		return ret;
	ret = 1e9;
	for (int i = 1; i <= n; i++)
		ret = min(ret, solve(hav - arr[i]) + 1);
	
	return ret;
}
int32_t main() 
{
	fast();
	for (int i = 0; i < N; i++)
		dp[i] = 1e9;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[0] = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int prev = i - arr[j];
			if (prev >= 0)
				dp[i] = min(dp[i], 1+dp[prev]);
		}
	}
	if (dp[x] >= 1e9)
		dp[x] = -1;
	cout << dp[x] << endl;
}
