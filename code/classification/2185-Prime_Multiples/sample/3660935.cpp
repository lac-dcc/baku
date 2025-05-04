#include<bits/stdc++.h>
#define f first
#define sec second
#define pb push_back
using namespace std;
const long long MOD = 1000000000 + 7;
#define int long long
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
 
	vector<int>v(k);
	for (int &x : v)cin >> x;
	int ans = 0;
 
	for (int i = 1; i < (1 << k); i++) {
		int curr = 1, cnt = 0;
		bool ok = 1;
		for (int j = 0; j < k; j++) {
 
			if ((i >> j) & 1) {
				if (v[j] >= n / curr + 1) {
					ok = 0;
					break;
				}
				curr *= v[j], cnt++;
			}
 
		}
		if (ok) {
			if (cnt % 2)
				ans += (n / curr);
			else ans -= (n / curr);
		}
	}
 
	cout << ans;
 
 
 
}
