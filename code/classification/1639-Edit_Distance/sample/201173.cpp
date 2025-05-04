#include <bits/stdc++.h>
using namespace std;
 
int dp[5001][5001];
const int INF = 1e9;
 
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i + j > 0) dp[i][j] = INF;
			if(i) dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
			if(j) dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
			if(i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
		}
	}
	cout << dp[n][m] << '\n';
}