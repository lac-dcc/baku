#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}
 
int main() {
    // freopen("movie_festivalII.in", "r", stdin);
 
	int n, k; cin >> n >> k;
 
	vector<pair<int, int>> v(n);
 
	for (int i = 0; i < n; i++) // read start time, end time
		cin >> v[i].first >> v[i].second;
 
	sort(begin(v), end(v), comp); // sort by end time        (v[i].first, v[i].second) = (end_time, start_time)
 
	int maxMovies = 0;
	multiset<int> end_times; // times when members will finish watching movies, or when members are ready to watch
	for (int i = 0; i < k; ++i) end_times.insert(0);
 
	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].first);
 
//		if (it == begin(end_times)) continue;
		if (it == end_times.begin()) continue;
 
		// assign movie to be watched by member in multiset who finishes at time *prev(it)
		end_times.erase(--it);
		// member now finishes watching at time v[i].first
		end_times.insert(v[i].second);
 
		++maxMovies;
 
	}
 
	cout << maxMovies;
}