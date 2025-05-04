// Solved by: Shoumya
 
#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long int
 
void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
 
void solve() {
	string a, b; cin >> a >> b;
	int lenA = a.size(), lenB = b.size();
	vector<vector<int> > dp(lenA + 1, vector<int> (lenB + 1, 1e9 + 7));
	dp[0][0] = 0;
 
	for (int i = 0; i <= lenA; i++) {
		for (int j = 0; j <= lenB; j++) {
			if (i)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
 
			if (j)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
 
			if (i and j)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
		}
	}
 
	cout << dp[lenA][lenB] << endl;
}
 
int main() {
	fastIO();
 
	solve();
 
	return 0;
}