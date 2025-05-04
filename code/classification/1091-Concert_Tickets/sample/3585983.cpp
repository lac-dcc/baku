#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
 
using namespace std;
 
signed main() {
	int n, m;
	cin >> n >> m;
	multiset<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.insert(a);
	}
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		if (v.size() < 1) {
			cout << -1 << "\n";
			continue;
		}
		
		auto it = v.upper_bound(c);
		
		if (it != v.begin()) {
			cout << *(--it) << "\n";
			v.erase(it);
		}
		else {
			cout << -1 << "\n";
		}
	}
}
