#include <iostream>
#include <vector>
#include <algorithm>
struct triplet { int a; int b;long long p; };
bool comp(triplet x, triplet y) {
	if (x.b == y.b) {
		return x.a < y.a;
	}
	else {
		return x.b < y.b;
	}
}
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<triplet> m(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i].a >> m[i].b >> m[i].p;
	}
	sort(m.begin(), m.end(), comp);
	 vector <pair<int, long long>> tot;
	 tot.push_back(pair<int, long long>(m[0].b, m[0].p));
	for (int i = 1; i < n; i++) {
		pair <int, long long> x = make_pair(m[i].a, 0);
		auto it = lower_bound(tot.begin(), tot.end(),x, [](const pair<int, long long>& x, const pair<int, long long>& y) {return x.first < y.first;});
		if(it != tot.begin()){
			it--;
			long long op1 = m[i].p + (*it).second;
			long long op = max(op1, tot[i - 1].second);
			tot.push_back(pair<int, long long>(m[i].b, op));
		}
		else {
			long long op = max(m[i].p, tot[i - 1].second);
			tot.push_back(pair <int, long long>(m[i].b, op));
		}
	}
	cout << tot[n - 1].second;
	return 0;
}
