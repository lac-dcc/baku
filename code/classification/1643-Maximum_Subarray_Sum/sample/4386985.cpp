#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln "\n"
const int maxN = 2e5;
const ll INF = 1e10;
 
int n;
ll a[maxN + 1];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
 
	ll ans = -INF;
	ll s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		ans = max(ans, s);
		s = max(s, 0LL);
	}
	cout << ans;
	return 0;
}