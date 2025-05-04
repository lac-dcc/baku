#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].second >> v[i].first;
	sort(begin(v), end(v));
	int maxMovies = 0;
	multiset<int> end_times;
	for (int i = 0; i < k; ++i) end_times.insert(0);
	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].second);
		if (it == begin(end_times)) continue;
		end_times.erase(--it);
		end_times.insert(v[i].first);
		++maxMovies;
	}
 
	cout << maxMovies;
}
