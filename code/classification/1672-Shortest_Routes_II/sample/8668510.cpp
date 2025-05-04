#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma")
using namespace std;
using namespace chrono;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update> o_set;
/*
    s.find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set s
	s.order_of_key(k) : It returns to the number of items that are strictly smaller than our item k
*/
//multiordered_set , helper_fun : https://github.com/vekariyasagar54/CP/blob/main/GenFun.md
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> mo_set;
 
#define fastio()        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD             1000000007
#define inf             1e18
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define ff              first
#define ss              second
#define PI              3.141592653589793238462
#define sz(x)           ((int)(x).size())
#define all(x)          (x).begin(), (x).end()
#define forf(n , ch)    for(int ch = 0 ; ch < (n) ; ch++)
#define forr(n , ch)    for(int ch = (n) ; ch >= 0 ; ch--)
#define for0(n,i)       for(int i = 0; i < (int)(n); ++i)
#define for1(n,i)       for(int i = 1; i <= (int)(n); ++i)
#define forc(i,l,r)     for(int i = (int)(l); i <= (int)(r); ++i)
#define min3(a,b,c)     min(c, min(a, b))
#define min4(a,b,c,d)   min(d, min(c, min(a, b)))
#define inp(n,arr)      for(int __i = 0; __i < n ; __i++) cin >> arr[__i]
#define dbg(arr)        for(auto &i : arr) cout<<i<<" "
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define rtn             return
#define lb 				lower_bound
#define ub 				upper_bound
#define nwl             cout<<"\n"
 
 
//data-type
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
using str = string;
 
//int container
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef pair<int, int>   pii;
typedef vector<pii>     vii;
 
 
//ll container
typedef vector<ll>      vl;
typedef vector<vl>      vvl;
typedef pair<ll, ll>     pll;
typedef vector<pll>     vll;
 
//bool container
typedef vector<bool>    vb;
typedef vector<vb>      vvb;
 
//string container
typedef vector<str>     vs;
 
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
 
 
 
void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	vvl g( n + 1 , vl(n + 1, inf));
	vvl dis( n + 1 , vl(n + 1, inf));
	forf(m, i)
	{
		ll a , b , c;
		cin >> a >> b >> c;
		g[a][b] = min(c, g[a][b]);
		g[b][a] = min(c, g[a][b]);
	}
 
	for1(n , i)
	{
		for1(n, j)
		{
			dis[i][j] = g[i][j];
		}
	}
	forf(n + 1, i)dis[i][i] = 0;
 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
 
 
				if (dis[i][k] == inf
				        || dis[k][j] == inf)
					continue;
 
				if (dis[i][j] > dis[i][k]
				        + dis[k][j]) {
					dis[i][j] = dis[i][k]
					            + dis[k][j];
 
				}
			}
		}
	}
 
 
	while (q--)
	{
		int a , b;
		cin >> a >> b;
		if (dis[a][b] == inf)
		{
			cout << "-1\n";
		}
		else cout << dis[a][b] << "\n";
	}
 
 
}
 
 
int main() {
 
#ifndef ONLINE_JUDGE
 
	freopen("input.txt", "r", stdin);
 
	freopen("output.txt", "w", stdout);
 
#endif
	fastio();
	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve();
	// }
 
}