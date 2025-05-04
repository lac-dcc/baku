#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	set<int> s;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int k; cin >> k;
		s.insert(k);
	}
 
	cout << s.size() << "\n";
 
return 0;
 
}
