/*
    author: Rishi Mohan Jha
    created_at: 28-06-2022  07:27 PM
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
 
#define ll        long long
#define ff        first
#define ss        second
#define pb        push_back
#define sz(x)     ((int)(x).size())
#define all(a)    (a).begin(),(a).end()
 
void Solve() {
	int n, x;
	cin >> n >> x;
 
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].ff;
		v[i].ss = i;
	}
 
	sort(all(v));
 
	for (int i = 0; i + 3 < n; i++) {
		for (int j = i + 3; j < n; j++) {
			int l = i + 1, r = j - 1;
			while (l < r) {
				int sum = v[l].ff + v[r].ff;
				if (sum == x - v[i].ff - v[j].ff) {
					cout << v[i].ss + 1 << ' ' << v[j].ss + 1 << ' ' << v[l].ss + 1 << ' ' << v[r].ss + 1 << endl;
					return;
				}
 
				if (sum > x - v[i].ff - v[j].ff) {
					r--;
				}
				else {
					l++;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int t = 1;
	while (t--) Solve();
}
