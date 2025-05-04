#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
	int n; cin >> n;
	int a[n];
	ll ans = -1e12, tmp = -1e12;
	for (int i = 0; i < n; i++) {
		ll t; cin >> t;
		tmp = max(t, tmp + t);
		ans = max(ans, tmp);
	}
	cout << ans;
 	
	return 0;
}