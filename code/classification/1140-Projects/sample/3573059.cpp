#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;
 
typedef long long ll;
ll MOD = 1000000007;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<pair<pair<int, int>, ll>> v(n);
	for (auto &i : v) cin >> i.first.second >> i.first.first >> i.second;
	sort(v.begin(), v.end());
	
	vector<int> li;
	for (auto i : v) li.push_back(i.first.first), li.push_back(i.first.second);
	sort(li.begin(), li.end());
	
	for (auto &i : v) {
		i.first.first = lower_bound(li.begin(), li.end(), i.first.first) - li.begin() + 1;
		i.first.second = lower_bound(li.begin(), li.end(), i.first.second) - li.begin() + 1;
	}
	
	vector<ll> dp(2 * n + 1);
	int pre = 1;
	for (auto i : v) {
		for (int j = pre; j <= i.first.first; ++ j)
			dp[j] = max(dp[j], dp[j - 1]);
		pre = i.first.first;
 
		dp[i.first.first] = max(dp[i.first.first], dp[i.first.second - 1] + i.second);
	}
	cout << *max_element(dp.begin(), dp.end());
}
