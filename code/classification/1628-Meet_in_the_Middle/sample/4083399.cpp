// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;
 
int leftMost(vll& v, ll x) {
	int l = 0, r = v.size()-1;
	while(l <= r) {
		int m = l+(r-l)/2;
		if(v[m] >= x) r = m-1;
		else l = m+1;
	}
	return l;
}
 
int rightMost(vll& v, ll x) {
	int l = 0, r = v.size()-1;
	while(l <= r) {
		int m = l+(r-l)/2;
		if(v[m] <= x) l = m+1;
		else r = m-1;
	}
	return r;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k = 0; ll x; cin >> n >> x;
	vll v(n), rgt((1LL << ((n+1)/2)), 0LL);
	for(ll& i : v)
		cin >> i;
	for(ll i = (1LL << (n/2)); i < (1LL << n); i += (1LL << (n/2))) {
		ll s = 0;
		for(int j = n-1; j >= n/2; j--)
			if((i >> j)&1) s += v[j];
		rgt[k++] = s;
	}
	ll ans = 0;
	sort(rgt.begin(), rgt.end());
	for(ll i = 0; i < (1LL << (n/2)); i++) {
		ll s = 0;
		for(int j = n/2-1; j >= 0; j--)
			if((i >> j)&1) s += v[j];
		int p = rightMost(rgt, x-s), q = leftMost(rgt, x-s);
		ans += (p-q+1);
	}
	cout << ans << "\n";
	return 0;
}
