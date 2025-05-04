#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	set<int> s;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
 
	cout << s.size() << endl;
}
