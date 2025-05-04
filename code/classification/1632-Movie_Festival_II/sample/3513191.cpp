#include <bits/stdc++.h>
 
#define ll long long
#define ar array
 
using namespace std;
 
const int mxN = 2e5;
int n;
 
int main() {
	int s = 0;
	int k;
	cin >> n >> k;
	multimap<int, int> m; 
	multiset<int> end;
	while (n--) {
		int a, b;
		cin >> a >> b;
		m.insert({b, a});
	}
 
	for (int i = 0; i < k; i++){
		end.insert(0);
	}
 
	for (auto it = m.begin(), next = it; it != m.end(); it = next) {
		++next;
		auto it2 = end.upper_bound(it->second);
		if (it2 == end.begin()) continue;
		end.erase(--it2);
		end.insert(it->first);
		s++;
	}
	
	cout << s;
 
}
