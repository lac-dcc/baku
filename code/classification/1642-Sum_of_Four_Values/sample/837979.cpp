// Author: Omar_Elaraby
// Created: ٢٠٢٠-٠٨-١٣ ٢:٣٤:٢٨ ص
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int &i : v) {
		cin >> i;
	}
 
	map<int, pair<int, int> > mp;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			int y = x - v[i] - v[j];
			if (mp.count(y)) {
				cout << i + 1 << ' ' << j + 1 << ' ' << mp[y].first + 1 << ' '
						<< mp[y].second + 1 << '\n';
				return 0;
			}
		}
 
		for (int j = 0; j <= i; ++j) {
			mp[v[i] + v[j]] = make_pair(i, j);
		}
	}
	cout << "IMPOSSIBLE\n";
 
	return 0;
}
