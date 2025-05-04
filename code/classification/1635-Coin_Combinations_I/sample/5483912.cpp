#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;
const ll base = 137;
const int inf = 2e9;
const int lim = 1e6 + 5;
 
// link : https://cses.fi/problemset/task/1635
 
int n, x, c[lim], dp[lim];
 
int main()
{
	cin.tie(0) -> ios_base::sync_with_stdio(0);
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	dp[0] = 1;
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i >= c[j])
				dp[i] = (dp[i] + dp[i - c[j]]) % mod;
		}
	cout << dp[x];
}