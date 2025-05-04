#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
using ll = long long;
 
int main(){
	int p, w;
	cin >> p >> w;
 
	vector<int> price(p), weight(p);
 
	for(int i = 0; i < p; ++i)
		cin >> price[i];
	for(int i = 0; i < p; ++i)
		cin >> weight[i];
 
	vector<vector<int>> dp(p + 1, vector<int> (w + 1, 0));
	for(int i = 1; i <= p; ++i){
		for(int j = 1; j <= w; ++j){
			if(j - price[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], weight[i - 1] + dp[i - 1][j - price[i - 1]]);
			else
				dp[i][j] = dp[i-1][j];
		}	
	}
	cout << dp[p][w] << endl;
	return 0;
}