#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <optional>
#include <unordered_map>
#include <stack>
using namespace std;
#define ll long long 
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (auto& i : coins) { cin >> i; }
	vector<optional<int>> dp(x + 1);
	dp[0] = 0;
	for (int i = 1; i < x + 1; i++) { dp[i] = {}; }
	for (int i = 1; i <= x; i++) {
		//if (i == 1000) cin >> x;
		int mini=-1;
		int j = 0;
		while(j<n){
			if (coins[j] > i) { j++; continue; }
			if (dp[i - coins[j]].has_value()) {
				if (mini == -1) mini = (* dp[i - coins[j]]);
				else {
					mini = min(mini, *dp[i - coins[j]]);
				}
			}
			j++;
		}
		if (mini == -1) dp[i] = {};
		else dp[i] = mini + 1;
	}
	if (!dp[x].has_value()) cout << -1;
	else cout << *dp[x] << endl;
	return 0;
}