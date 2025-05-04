#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
 
#define PB push_back
#define PF push_front
#define F first
#define S second
#define rep(i,n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
typedef unsigned int uint;
typedef long long ll;
typedef long long unsigned int llui;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
bool comp(array<int, 3> a, array<int, 3> b) {
	return a[1] < b[1];
}
 
int main() {
	int n;
	cin >> n;
 
	vector<array<int, 3>> v(n, array<int, 3> {0});
	map<ll, int, greater<ll>> m; //<endtime, reward>
 
	rep(i,n)
		cin >> v[i][0] >> v[i][1] >> v[i][2];
 
	sort(v.begin(), v.end(), comp);
 
	rep(i,n) {
		const auto [it, t] = m.insert({v[i][1], i});
 
		if(!t)
			it->S++;
	}
 
	vector<llui> dp(n);
	dp[0] = v[0][2];
	for(int time = 1; time < n; ++time) {
		auto ub = m.upper_bound(v[time][0]);
 
		if(ub != m.end())
			dp[time] = max(llui(v[time][2] + dp[ub->S]), llui(dp[time - 1]));
		else {
			dp[time] = max(llui(v[time][2]), dp[time - 1]);
		}
	}
 
	cout << dp[n - 1];
 
    return 0;
}