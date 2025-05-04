#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = INT_MAX;
const int n_inf = INT_MIN;
const int mod = 1e9 + 7;
#pragma GCC optimize("Ofast")
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); };
int d2[8][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };
 
int main () {
 
	int n, x;
	cin >> n >> x;
 
	vector<int>arr(n);
	for(auto& a : arr) cin >> a;
 
	vector<vector<int>>dp(n + 1, vector<int>(x + 1));
	dp[0][0] = 1;
 
	for(int i = 1; i <= n; i++) {
		for(int s = 0; s <= x; s++) {
			dp[i][s] = dp[i-1][s];
			if(s >= arr[i-1]) {
				dp[i][s] = ( dp[i][s] + dp[i][s - arr[i-1]] ) % mod;
			}
		}
	}
 
	cout << dp[n][x];
 
    return 0;
}
