#include<bits/stdc++.h>
 
using namespace std;
const int M = 1e9+7;
const int INF = 1e9;
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for(int i = 0;i < n; ++i){
		cin >> v[i];
	}
	vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
	dp[0][0] = 1;
	for(int i = 1;i <= n; i++){
		for(int j = 0;j <= x; j++){
			dp[i][j] = dp[i - 1][j];;
			if(j - v[i - 1] >= 0){
				(dp[i][j] += dp[i][j - v[i - 1]]) %= M;
			}
		}
	}
	cout << dp[n][x];
}
