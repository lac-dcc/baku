#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	int n;
	cin >> n;
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mp[a]++;
		mp[b]--;
	}
	int ans = 0;
	int cnt = 0;
	for (auto e : mp) {
		cnt += e.second;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
 
}
