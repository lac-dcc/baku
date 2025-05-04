// movies sorted by end times in an array
// movies played at this moment in a multiset
//		with sort criteria on ascending end time
// NO - first fill in the multiset up to a size of k - NO
// first fil in the multiset with zeros
// greedy: the next movie replaces the movie in the multiset
//		whose end time is before the new begin time,
//		but whose end time is as big as possible, in order to allow
//		the other movies with sooner begin time to be seen
//		(films sorted by end time)
 
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<pii> movies(n); // first: start time, second: end time
	for(auto& movie: movies)
		cin >> movie.first >> movie.second;
	sort(movies.begin(), movies.end(), [](pii& a, pii& b){
		return a.second < b.second;
	});
	multiset<int> endTimes;
	for(int i=0; i<k; i++)
		endTimes.insert(0);
	int answer = 0;
	for(auto& movie: movies) {
		auto it = endTimes.upper_bound(movie.first);
		if(it == endTimes.begin()) // new begin time < first end time
			continue;
		answer++;
		it--;
		endTimes.erase(it);
		endTimes.insert(movie.second);
	}
	cout << answer << endl;
}
