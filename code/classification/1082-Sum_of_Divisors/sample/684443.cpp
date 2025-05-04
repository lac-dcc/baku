#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll n,ans;
int main() {
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll r = n/(n/i);
		ans += n/i%mod*(r%mod* ((r+1)%mod)%mod - (i%mod)*((i-1)%mod)%mod)%mod*(mod+1)/2%mod;
		i = r;
	}
	cout << (ans%mod+mod)%mod;
return 0;
}
