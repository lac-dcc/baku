#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int, int>&a, pair<int, int>&b)
{
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<pair<int, int>>a;
	multiset<int>s;
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		a.push_back({x, y});
	}
	sort(a.begin(), a.end(), mycmp);
	for (int i = 0; i < k; ++i)
		s.insert(-1);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		auto it = s.lower_bound(a[i].first);
		if (it != s.end() && *it == a[i].first)
		{
			s.erase(it);
			s.insert(a[i].second);
			ans++;
		}
		else
		{
			if (it == s.begin())
				continue;
			it--;
			s.erase(it);
			s.insert(a[i].second);
			ans++;
		}
	}
	cout << ans;
	return 0;
}


