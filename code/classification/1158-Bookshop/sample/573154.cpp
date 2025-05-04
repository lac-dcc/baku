#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
 
typedef long long ll;
 
using namespace std;
 
int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 0; i <= x; ++i) {
		dp[0][i] = 0;
	}
	int c = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= x; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - a[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
			}
			c = max(c, dp[i][j]);
		}
	}
	cout << c;
}