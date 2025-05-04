/* Abhishek Agrahari */
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <array>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define B begin()
#define E end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define F first
#define S second
// #define int ll
#define fo(i,a,b)     for(int i=(a);i<=(b);i++)
#define fill(a,b) memset((a), (b), sizeof((a)))
#define setbits(x) __builtin_popcountll((x))
#define sz(x) ((int)(x).size())
#define nline cout << "\n"
#define sp " "
#define range(a,b) substr((a),(b)-(a)+1)
#define pii pair<int,int>
#define vi vector<int>
#ifdef Abhishek
#define deb(x...) cerr << "[" << #x << "] = ["; __print(x)
#else
#define deb(x...)
#endif
#define inf 1000000000000000000LL //1e18
#define INF 1000000000LL //1e9
#define MOD 1000000007 //998244353LL
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
// 1) x & (x - 1):sets the last one bit of x to zero
// power of two exactly when x & (x - 1) = 0.
// 2)x & -x:sets all the one bits to zero, except last one bit
// 3)x | (x - 1):inverts all the bits after the last one bit
//clear adj and visited vector declared globally after each test case
//Mod wale question mein last mein if dalo ki ans<0 then ans+=mod;
//Incase of close mle change language to c++17 or c++14
// find_by_order(k)  returns iterator to kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k
//cout<<fixed<<setprecision(15)<<ans;
//getline(cin, str);
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}
// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(oset<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void __print() {cerr << "]\n";}
// template <typename T, typename... V> void __print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; __print(v...);}
//_____________________________________________________________________________________________________________________________________________________________
// ll expo(ll a, ll b, ll mod = MOD) {a %= mod; ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
// ll lcm(ll a, ll b) { ll x = gcd(a, b); ll ans = (a * b) / x; return ans; }
// int extendedGCD(int a, int b, int &x, int &y) {if (b == 0) {x = 1; y = 0; return a;} int x1, y1; int d = extendedGCD(b, a % b, x1, y1); x = y1; y = x1 - (a / b) * y1; return d;}
// void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
// ll modInverse(ll n, ll t = MOD) { return expo(n, t - 2, t);}
// void factors(ll n) {vi factor; for (ll i = 1; i * i <= n; i++) if (n % i == 0) { if (n / i == i) factor.pb(i); else {factor.pb(i); factor.pb(n / i);}}}
// ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ull nCrModPFermat(ll n, ll r) {if (n < r) return 0; if (r == 0) return 1; vector<ull> fac(n + 1); fac[0] = 1; for (ll i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD; return (fac[n] * modInverse(fac[r], MOD) % MOD * modInverse(fac[n - r], MOD) % MOD) % MOD;}
// const int m = 1e5; vector<int> prime(m + 5); void sieve() {fo(i, 0, m) {prime[i] = 1;} prime[0] = 0; prime[1] = 0; for (int p = 2; p * p <= m; p++) {if (prime[p] == 1) {for (int i = p * p; i <= m; i += p)prime[i] = 0;}}} //it gives prime status of nos upto m.
//____________________________________________________________CODE STARTS ____________________________________________________________
 
int dp[1001][100001];
void solve()
{
	int n, w;
	cin >> n >> w;
	int cost[n + 1], page[n + 1];
	fo(i, 1, n) cin >> cost[i];
	fo(i, 1, n) cin >> page[i];
	int ans = 0;
	fo(i, 1, n) {
		fo(j, 1, w) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (cost[i] <= j) dp[i][j] = max(dp[i][j], page[i] + dp[i - 1][j - cost[i]]);
			if (i == n) {
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans << nl;
}
 
 
signed main() {
#ifdef Abhishek
	freopen("Error.txt", "w", stderr);
#endif
	fastio();
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
#ifdef Abhishek
		cerr << "----" << i << "----" << nl;
		cout << "----" << i << "----" << nl;
#endif
		solve();
	}
	return 0;
}