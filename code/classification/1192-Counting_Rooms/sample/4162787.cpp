#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
typedef long long ll;
 
ll n, m;
char grid[1010][1010];
ll vis[1010][1010];
ll X[4] = { -1, 0, 0, 1};
ll Y[4] = {0, -1, 1, 0};
 
bool isvalid(ll x, ll y) {
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= n) return false;
	if (y >= m) return false;
	if (grid[x][y] == '#') return false;
	return true;
}
 
void dfs(ll n0, ll m0) {
	vis[n0][m0] = 1;
	for (ll i = 0; i < 4; i++) {
		ll xd = n0 + X[i];
		ll yd = m0 + Y[i];
		if (isvalid(xd, yd)) {
			if (!vis[xd][yd]) {
				dfs(xd, yd);
			}
		}
	}
}
 
void solve() {
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (!vis[i][j] && grid[i][j] == '.') {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}
 
int main() {
	ll t = 1;
	while (t--) {
		solve();
	}
}
