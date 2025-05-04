#include <bits/stdc++.h>
 
using namespace std;
 
bool comp(pair<int, int> &l, pair<int, int> &r)
{
	return l.second < r.second;
}
int main()
{
	int n, k;
	vector<pair<int, int> > movie;
	multiset<int> S;
 
	cin >> n >> k;
 
	for (int i = 1; i <= n; i++) {
		pair<int, int> m;
		cin >> m.first >> m.second;
		movie.push_back(m);
	}
	sort(movie.begin(), movie.end(), comp);
 
	for (int i = 1; i <= k; i++)
		S.insert(0);
 
	int ans = 0;
	for (int i = 0; i < n; i++) {
		multiset<int>::iterator it = S.upper_bound(movie[i].first);
		if (it != S.begin()) {
			ans++;
			it--;
			S.erase(it);
			S.insert(movie[i].second);
		}
	}
 
	cout << ans << endl;
 
	return 0;
}
