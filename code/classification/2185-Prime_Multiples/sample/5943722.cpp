#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) {/* AAAAAAAA; */}
#endif
 
using LL = long long;
using PII = pair<int,int>;
 
int main()	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LL n; int k; 
	cin >> n >> k;
	vector<LL> a(k);
	LL ans = 0;
	for(auto &i: a) cin >> i;
	for(int i=1; i<(1<<k); i++) {
		LL at = 1; 
		int cnt = ((__builtin_popcount(i)) & 1);
		bool ok = true;
		for(int bit=0; bit<k; bit++) {
			if(i & (1 << bit)) {
				if(at > n / a[bit])
					ok = false;
				at *= a[bit];
			}
		}
		if(!ok) continue;
		if(cnt & 1) ans += n / at;
		else ans -= n / at;
	}
	cout << ans;
}