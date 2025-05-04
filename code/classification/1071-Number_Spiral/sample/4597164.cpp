#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t, x, y;
 
	cin >> t;
 
	while (t--) {
		cin >> y >> x;
 
		long long val = max(x, y) - 1;
		val *= val;
		if (max(x, y) % 2 != 0)
			swap(x, y);
		long long ans = y;
		if (y >= x)
			ans += y - x;
 
		cout << val + ans << endl;
	}
}
