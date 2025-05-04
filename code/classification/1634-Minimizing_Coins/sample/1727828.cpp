#include<bits/stdc++.h>
using namespace std;
 
#define fo(i,n) for(i = 0 ; i < n ; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define nl "\n"
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define PI 3.141592653589793238
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<lli, lli> plli;
typedef priority_queue<lli> pqb;
typedef priority_queue<lli, vector<lli>, greater<lli>> pqs;
 
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
void GO_GO_GO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
 
void BYE_BYE() {cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";}
 
bool primeArr[1000001] = {false};
 
lli fact[1000001];
 
lli lazy[1000001] = {0};
 
vector<lli> primes;
 
/****************************************************************************************/
int main() {
	GO_GO_GO();
 
	lli t = 1;
	// cin >> t;
	while (t--) {
		lli i = 0;
		lli j = 0;
		lli n, x;
		cin >> n >> x;
		vector<lli> v(n);
		fo(i, n) cin >> v[i];
		int dp[n + 1][x + 1];
		for (int i = 0 ; i < x + 1 ; i++) {dp[0][i] = INT_MAX - 1;}
		for (int i = 1 ; i < n + 1 ; i++) {dp[i][0] = 0;}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= x ; j++) {
				if (v[i - 1] > j) {dp[i][j] = dp[i - 1][j];}
				if (v[i - 1] <= j) {
					dp[i][j] = min(dp[i][j - v[i - 1]] + 1, dp[i - 1][j]);
				}
			}
		}
		dp[n][x] != INT_MAX - 1 ? cout << dp[n][x] : cout << -1;
	}
	BYE_BYE();
	return 0;
}