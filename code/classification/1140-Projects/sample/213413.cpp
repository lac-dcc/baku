#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<tuple<int,int,int>> a(n+1);
	a[0] = make_tuple(0, 0, 0);
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[i] = {y, x, z};
	}
 
	sort(a.begin(), a.end());
	//for (auto x : a) fprintf(stderr, "%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
	vector<long long> dp(n+1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		int j = lower_bound(a.begin(), a.end(), make_tuple(get<1>(a[i]), 0, 0)) - a.begin() - 1;
		if (j >= 0 && get<0>(a[j]) < get<1>(a[i]))
			dp[i] = max(dp[i], dp[j] + get<2>(a[i]));
	}
	//for (long long x : dp) fprintf(stderr, "%lld ", x); fprintf(stderr, "\n");
	cout << dp[n] << endl;
}