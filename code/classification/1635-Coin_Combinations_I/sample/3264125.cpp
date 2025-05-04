#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n, x;
	int m = 1000000007;
	cin >> n >> x;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<int> dp(x+1);
	dp[0] = 1;
	for(int i = 0; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i + v[j] <= x){
				dp[i + v[j]] += dp[i];
				dp[i + v[j]] %= m;
			}
		}
	}
	cout << dp[x];
}