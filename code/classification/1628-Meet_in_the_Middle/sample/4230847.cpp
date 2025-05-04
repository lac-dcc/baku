#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>
using namespace std;
#define int long long
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	unordered_map<int, int, custom_hash> mp1;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int n1 = n >> 1;
	int n2 = n - n1;
	if (n == 1)
	{
		cout << (v[0] == x);
		return 0;
 
	}
	vector<int> pre;
	for (int i = 1; i <= n1; i++)
	{
		if (i == 1)
		{
			mp1[0]++;
			if (v[0] <= x) mp1[v[0]]++;
			pre.push_back(0);
			pre.push_back(v[0]);
		}
		else
		{
			int sz = pre.size();
			for (int j = sz - 1; j >= 0; j--)
			{
				if (pre[j] + v[i - 1] <= x)
				{
					mp1[pre[j] + v[i - 1]]++;
				}
				pre.push_back(pre[j] + v[i - 1]);
			}
		}
	}
	int ans = 0;
	vector<int> PRE;
	for (int i = 1; i <= n2; i++)
	{
		if (i == 1)
		{
			if (mp1.count(x)) ans += mp1[x];
			if (mp1.count(x - v[n1])) ans += mp1[x - v[n1]];
			PRE.push_back(0);
			PRE.push_back(v[n1]);
		}
		else
		{
			int sz = PRE.size();
			for (int j = sz - 1; j >= 0; j--)
			{
				auto it = mp1.find(x - PRE[j] - v[n1 + i - 1]);
				if (it != mp1.end()) ans += it->second;
				PRE.push_back(PRE[j] + v[n1 + i - 1]);
			}
		}
	}
	cout << ans;
	return 0;
}
