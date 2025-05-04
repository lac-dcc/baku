#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
	ll n, x;pair<ll,ll> a[1000000];
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			ll cnt1 = j + 1;
			ll cnt2 = n - 1;
			while (cnt1 < cnt2) {
 
				if (a[i].first + a[j].first +a[cnt1].first + a[cnt2].first == x) {
					cout << a[i].second << " " << a[cnt1].second << " " << a[cnt2].second<<" "<<a[j].second; return;
				}
				else if (a[i].first + a[cnt1].first + a[cnt2].first+ a[j].first < x) {
					cnt1++;
				}
				else { cnt2--; }
			}
		}
	}
	cout << "IMPOSSIBLE";
}
int main()
{
	solve();
}
