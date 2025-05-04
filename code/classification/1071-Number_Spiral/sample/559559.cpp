#include <bits/stdc++.h>
 
#define debug(a) cout << #a << " " << a << endl;
#define _debug(a, i) cout << #a << "[" << i << "]" << " = " << a[i] << endl;
#define fastio ios_base::sync_with_stdio(false); \
			cin.tie(0);							 \
			cout.tie(0);
#define PI 3.141592654
 
using namespace std;
 
using ll = long long;
const int MOD = 998244353;
const ll INF = 1e18 + 9;
 
ll powmod(ll base, ll exp, const ll MOD) { ll ans = 1; while (exp) { if (exp & 1)	ans = (ans * base) % MOD; base = (base * base) % MOD; exp >>= 1; } return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll modInverse(ll n, const ll p) { return powmod(n, p - 2, p); }
void add(ll& x, ll v) { x = (x + v) % MOD; if (x < 0) x += MOD; }
//ll f[500005];
//ll kCn(ll k, ll n) { return (f[n] * modInverse((f[n - k] * f[k]) % MOD, MOD)) % MOD; }
 
 
int a[50][50];
 
int main() {
	fastio;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	while(t--) {
			ll y, x;
			cin >> y >> x;
			ll z = 1;
			if (y > x) {
				if (y % 2 == 0) {
					z = y * y;
					z = z - x + 1;
				}
				else {
					z = (y - 1) * (y - 1) + 1;
					z = z + x - 1;
				}
			}
			else {
				
				if (x % 2 == 0) {
					z = (x - 1) * (x - 1) + 1;
					z = z + y - 1;
				}
				else {
					z = x * x;
					z = z - y + 1;
				}
				
			}
			cout << z << "\n";
	}
	return 0;
}