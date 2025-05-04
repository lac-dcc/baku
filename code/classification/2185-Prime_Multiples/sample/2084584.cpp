#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	ll n;
	int k;
	cin >> n >> k;
	ll a[k];
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	ll res = 0;
	for (int i = 1; i < (1 << k); ++i) {
		ll num = n;
		for (int j = 0; j < k; ++j) {
			if ((i & (1 << j)) > 0) {
				num /= a[j];
			}
		}
		res += (__builtin_popcount(i) % 2 == 1 ? num : -num);
	}
	cout << res;
	return 0;
}
