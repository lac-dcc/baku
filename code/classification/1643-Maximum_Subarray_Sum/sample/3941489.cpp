#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int INF = 1e9 + 7;
 
int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
 
	ll ans = 0, cS = 0, minS = INF;
	bool s = false;
	
	for(ll &i : v) {
		cin >> i;
 
		cS += i;
 
		if(ans <= cS - min(0ll, minS)) s = true;
		ans = max(ans, cS - min(0ll, minS));
 
		minS = min(cS, minS);
	}
 
	if(s)
		cout << ans << '\n';
	else
		cout << *max_element(v.begin(), v.end());
}
