#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stack>
#include <iterator>
#include <numeric>
#include <unordered_map>
 
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<ll, ll>
#define vii vector<ii>
#define ll long long
#define ull unsigned long long
#define oo 1000000007
#define oooo 1000000000000000007
#define maxN 100005
#define BLOCK 174
#define iii pair<ii, int>
#define TIME cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << " secs \n"
using namespace std;
int n, x, a[maxN], f[1005][maxN], h[maxN], s[maxN];
// int dp(int i, int x){
// 	if (i == 0 || x == 0) return 0;
// 	if (f[x] != -1) return f[x];
// 	int res = 0;
// 	if (h[i] <= x) res = max(dp(i - 1, x), dp(i - 1, x - h[i]) + s[i]);
// 	else res = dp(i - 1, x);
// 	return f[x] = res;
// }
void solve(){
	cin >> n >> x;
	for(int i = 1; i <= n; ++i) cin >> h[i];
	for(int i = 1; i <= n; ++i) cin >> s[i];
		for (int i = 1; i <= n; i++) {
		int curr_cost = h[i];
		int curr_pages = s[i];
		for (int j = 1; j <= x; j++) {
			f[i][j] = f[i - 1][j];
			if (curr_cost <= j) {
				f[i][j] = max(f[i][j], f[i - 1][j - curr_cost] + curr_pages);
			}
		}
	}
	cout << f[n][x] << '\n';
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#endif // ONLINE_JUDGE
 
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int t = 1; 
	// cin >> t;
	while(t--){
		solve();
	}
	TIME;
	return 0;
}
