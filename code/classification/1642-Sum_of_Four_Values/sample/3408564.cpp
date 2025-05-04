#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve() {
	int n;
	scanf("%d", &n);
 
	ll x;
	scanf("%lld", &x);
 
	vector<ll>v(n);
	for (ll &a : v) {
		scanf("%lld", &a);
	}
 
	multimap<ll, pair<ll, ll> >mp;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum = v[i] + v[j];
			if (mp.find(x - sum) != mp.end()) {
				auto it = mp.lower_bound(x - sum);
				auto jt = mp.upper_bound(x - sum);
				for (auto iit = it; iit != jt; iit++) {
					if (iit->second.first == i + 1 || iit->second.first == j + 1)continue;
					if (iit->second.second == i + 1 || iit->second.second == j + 1)continue;
					printf("%lld %lld %lld %lld", iit->second.first, iit->second.second, i + 1, j + 1);
					return;
				}
			}
			mp.insert({sum , { i + 1, j + 1}});
		}
	}
 
	printf("IMPOSSIBLE\n");
}
 
int main() {
 
	solve();
 
	return 0;
 
}