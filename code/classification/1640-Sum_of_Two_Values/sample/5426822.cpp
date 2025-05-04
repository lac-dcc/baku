#include <iostream>
#include <vector>
#include <set> 
#include <string> 
#include <algorithm>
#include <utility>
#include <math.h>
#include <map> 
#include <queue> 
#include <unordered_map> 
#define int long long 
using namespace std;
 
 
// const int N = 5050; 
// int dp[N][N];
 
 
 
void solve() {
	int n, x; cin >> n >> x;
	vector<pair<int, int> > v(n); 
	for(int i = 0; i < n; i++) {
		cin >> v[i].first; 
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		int l = -1, r = n;
		while(r - l > 1) {
			// cout << "l, r: " << l << " " << r << "\n"; 
			int m = (l + r) / 2;
			if(v[m].first <= x - v[i].first) l = m;
			else r = m; 
		}
		if(l != -1 && v[i].second != v[l].second && v[i].first + v[l].first == x) {
			cout << v[i].second + 1 << " " << v[l].second + 1 << "\n"; 
			return; 
		}
	}	
	cout << "IMPOSSIBLE\n"; 
}
 
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    // int tt = 1;
    // cin >> tt;
    // while(tt--) 
	
	solve();
}   
