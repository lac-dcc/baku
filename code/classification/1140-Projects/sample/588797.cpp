#include <bits/stdc++.h>
 
#define debug(a) cout << #a << " " << a << endl;
#define _debug(a, i) cout << #a << "[" << i << "]" << " = " << a[i] << endl;
#define fastio ios_base::sync_with_stdio(false); \
			cin.tie(0);							 \
			cout.tie(0);
#define PI 3.141592654
 
using namespace std;
 
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
 
ll powmod(ll base, ll exp, const ll MOD) { ll ans = 1; while (exp) { if (exp & 1)	ans = (ans * base) % MOD; base = (base * base) % MOD; exp >>= 1; } return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll modInverse(ll n, const ll p) { return powmod(n, p - 2, p); }
void add(ll& x, ll v) { x = (x + v) % MOD; if (x < 0) x += MOD; }
//ll f[500005];
//ll kCn(ll k, ll n) { return (f[n] * modInverse((f[n - k] * f[k]) % MOD, MOD)) % MOD; }
 
void test_case() {
 
}
 
const int mxN = 2e5 + 1;
int a[mxN], b[mxN], p[mxN];
 
int main() {
	fastio;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif // !ONLINE_JUDGE
 
	int n;
	cin >> n;
	map<int, int> compress;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> p[i];
		b[i]++;
		compress[a[i]], compress[b[i]];
	}
 
	int c = 0;
	for (auto& v : compress)
		v.second = c++;
 
	vector<vector<pair<int, int>>> proj(c);
	for (int i = 0; i < n; ++i)
		proj[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
 
	vector<ll> dp(c, 0);
	for (int i = 0; i < c; ++i) {
		if (i > 0)
			dp[i] = dp[i - 1];
		for (auto p : proj[i]) {
			dp[i] = max(dp[i], dp[p.first] + p.second);
		}
	}
	cout << dp[c - 1];
 
	return 0;
}