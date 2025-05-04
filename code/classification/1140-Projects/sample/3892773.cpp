#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > Tree;
// // find_by_order, order_of_key
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef unsigned long long ull;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)
 
#define sz(x) (long long)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
#define PI 3.1415926535897932384626
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int M1 = 1000000007;
const int M2 = 998244353;
const char nl = '\n';
 
/***************************************************************************************************************************/
 
ll modExp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
 
vector<bool> sieve(){
	int n = 1e6;
	vector<bool> prime(n+1,true);
	
    for (int p = 2; p * p <= n; p++)
    {
 
        if (prime[p] == true)
        {
 
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
	return prime;
}
 
#define MOD_VAL M1
 
ll inv(ll base) { return modExp(base, MOD_VAL-2, MOD_VAL); }
 
// Add template for extended euclidean algo to calculate inv for non-prime modulus
 
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
 
ll add(ll a, ll b) { a = a % MOD_VAL; b = b % MOD_VAL; return (((a + b) % MOD_VAL) + MOD_VAL) % MOD_VAL; }
ll mul(ll a, ll b) { a = a % MOD_VAL; b = b % MOD_VAL; return (((a * b) % MOD_VAL) + MOD_VAL) % MOD_VAL; }
ll sub(ll a, ll b) {a = a % MOD_VAL; b = b % MOD_VAL; return (((a - b) % MOD_VAL) + MOD_VAL) % MOD_VAL;}
ll dvd(ll a, ll b) { a = a % MOD_VAL; b = b % MOD_VAL; return (mul(a, inv(b)) + MOD_VAL) % MOD_VAL; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*************************************************DEBUGGING*****************************************************************/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/***************************************************************************************************************************/
#define int ll
 
struct Event{
	int start, end, price;
};
 
bool comp(Event a, Event b){
	return a.end < b.end;
}
 
void solve(){
	int n;cin>>n;
 
	vector<Event> v(n);
	
	F0R(i,n){
		int a,b,c;cin>>a>>b>>c;
 
		v[i].start = a;
		v[i].end = b;
		v[i].price = c;
	}
 
	sort(all(v), comp);
 
	vector<int> end_time(n);
	F0R(i,n){
		end_time[i] = v[i].end;
	}	
 
 
	int dp[n];
	memset(dp, 0, sizeof(dp));
 
	dp[0] = v[0].price;
 
	FOR(i,1,n){
		int idx = lower_bound(all(end_time), v[i].start) - end_time.begin();
 
		int prev = (idx-1>= 0) ? dp[idx-1] : 0;
 
		dp[i] = max(dp[i-1], 
					v[i].price + prev);
	}
 
	cout<<dp[n-1]<<nl;
}
 
signed main(){
	FIO
 
	int t=1;
	
	while(t--){
		solve();
	}
 
	return 0;
}