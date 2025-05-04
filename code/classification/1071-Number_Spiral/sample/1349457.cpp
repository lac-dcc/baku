#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> y >> x;
		long long z = max(y, x);
		long long zd = (z-1)*(z-1);
		long long ans;
		if (z % 2) {
			if (y == z) {
				ans = zd + x;
			} else {
				ans = zd + 2 * z- y;
			}
		} else {
			if (x == z){
				ans = zd + y;
			} else {
				ans = zd + 2 * z - x;
			}	
		}
		cout << ans << "\n";
	}
	return 0;
}
