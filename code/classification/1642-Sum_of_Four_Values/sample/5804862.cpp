#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define F first
#define S second
#define ii pair<int, int>
 
using namespace std;
 
const int N=1e6, M=1e9+7, INF=1e12, nINF=-1e12;
 
void solve() {
	int n, x; cin >> n >> x;
	int a[n+1];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
 
	map<int, ii> sum;
 
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int curr = a[i] + a[j];
			int rest = x - curr;
			if(sum[rest].F > 0) {
				cout << i+1 << ' ' << j+1 << ' ' << sum[rest].F+1 << ' ' << sum[rest].S+1;
				return;
			}
		}
 
		for(int k = 0; k < i; k++) {
			sum[a[i] + a[k]] = {i, k};
		}
	}
	cout << "IMPOSSIBLE";
}
 
signed main() { IOS
	int t=1;
	//cin >> t;
	while(t--) {
		solve();
 
	}
	return 0;
}