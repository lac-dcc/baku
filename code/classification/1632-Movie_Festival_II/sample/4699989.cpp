#include<bits/stdc++.h>
#define f first
#define sec second
#define pb push_back
using namespace std;
const long long MOD = 1000000000 + 7;
using ll = long long;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>v(n);
	for (auto &p : v)cin >> p.f >> p.sec;
	sort(v.begin(), v.end());
 
 
	multiset<pair<int, int>> st1;
	int ans = 0;
 
	for (int j = 0; j < n; j++) {
		int x = v[j].f, y = v[j].sec;
		while (st1.size() && st1.begin()->f <= x) {
			st1.erase(st1.begin());
		}
		if ((int)st1.size() < k) {
			st1.insert({v[j].sec, j});
			ans++;
			continue;
		}
		auto it = st1.upper_bound({y, -1});
		if (it == st1.end())continue;
		it = --st1.end();
 
 
		st1.erase(it);
 
		st1.insert({v[j].sec, j});
	}
	cout << ans;
 
}
