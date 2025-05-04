#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
vector<vector<int> > dp;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int n, have;
	cin >> n >> have;
	
	vector<int> p(n);
	for(int i = 0 ; i <p.size(); ++i){
		cin >> p[i];
	}
	vector<int> s(n);
	for(int i = 0; i < s.size(); ++i) {
		cin >> s[i];
	}
	
	dp.resize(n + 1);
	for(int i = 0; i <(int)dp.size();++i){
		dp[i].resize(have+1);
	}
	
	
	for(int i = n - 1; i >= 0; --i){
		for(int j = 1; j <= have; ++j){
			dp[i][j] = dp[i+1][j];
			if(j - p[i] >= 0){
				dp[i][j] = max(dp[i][j], s[i] + dp[i+1][j - p[i]]);
			}
		}
	}
	
	cout << dp[0][have] << '\n';
	
	return 0;
}