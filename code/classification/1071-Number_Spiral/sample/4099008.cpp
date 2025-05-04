#include<iostream>
#include <vector>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int t; cin >> t;
	long long c, r;
 
	for (int ix = 0; ix < t; ++ix) {
		cin >> r >> c;
		if (c > r) {
			if (c & 1) cout << c * c - r + 1;
			else cout << (c - 1) * (c - 1) + r;
		} else {
			if (r & 1) cout << (r - 1) * (r - 1) + c;
			else cout << r * r - c + 1;
		}
		cout << '\n';
	}
}
