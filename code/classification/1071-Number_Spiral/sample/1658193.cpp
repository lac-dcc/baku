#include <iostream>
using namespace std;
 
 
int main () {
	ios::sync_with_stdio (false); cin.tie (0);
 
	int t; cin >> t;
 
	while (t--) {
		long long y, x; cin >> y >> x;
 
		long long res;
		if (y >= x) {
			res = (y - 1) * (y - 1);
			if (y % 2 == 0) res += y + y - x;
			else res += x;
		}
		else {
			res = (x - 1) * (x - 1);
			if (x % 2 == 1) res += x + x - y;
			else res += y;
		}
 
		cout << res << '\n';
	}
 
	return 0;
}
