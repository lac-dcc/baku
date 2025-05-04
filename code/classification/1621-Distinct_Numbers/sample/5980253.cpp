#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t , a;
	
	cin >> t;
	
	std::set <int> b;
	
	for ( int i = 0; i < t; i ++ ) {
		cin >> a;
		b.insert(a);
	}
	
	cout << b.size() << endl;
	
	return 0;
}