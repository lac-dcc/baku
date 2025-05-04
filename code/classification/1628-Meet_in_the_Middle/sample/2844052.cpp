// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
// #pragma GCC optimize("unroll-loops")
 
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
string to_string(char c) {
	return string(1, c);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}
template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}
 
#define rep(i, a, b)    for(int i = (a); i < (b); ++i)
#define per(i, a, b)    for(int i = (a) ; i >= (b); i--)
#define forn(i,n)       rep(i,0,(n))
#define rof(i,n)        per(i,(n)-1,0)
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y,z)    cout << #x << "=" << x << "," << #y << "=" << y <<"," << #z << "=" << z << endl
#define ff              first
#define ss              second
#define mp              make_pair
#define all(x)          (x).begin(), (x).end()
#define sz(x)           (int)(x).size()
#define endl            "\n"
#define int             long long
#define ll              long long
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int>> // minheap
#define piipqs          priority_queue<pii,vector<pii>,greater<pii>> // minheap for pair<int,int>
#define piipqb          priority_queue<pii> // maxheap for pair<int,int>
#define mod             1000000007
// #define mod             998244353
#define memt(a)         memset(a,true,sizeof(a))
#define memf(a)         memset(a,false,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define meminf(a)       memset(a,0x7f,sizeof(a))
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0)
#define YES             cout<<"YES"<<endl
#define NO              cout<<"NO"<<endl
#define NEG1           	cout<<-1<<endl
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // set
// #define osetpii         tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> //like multiset
mt19937_64 				rng(chrono::steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
typedef tuple<int, int> tpl;
 
const ll inf = 2e18; //2e18
const double epsilon = 1e-7;
 
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
 
inline ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
 
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
// *********************************** Code Begins ************************************ //
 
int sum = 0;
 
void store(vector<int> &v, int pos, int en, unordered_map<int, int> &m)
{
	if (pos == en)
	{
		m[sum]++;
		return;
	}
	sum += v[pos];
	store(v, pos + 1, en, m);
	sum -= v[pos];
	store(v, pos + 1, en, m);
}
 
void solve()
{
	int n, x, ans = 0;
	cin >> n >> x;
	vector<int> v(n);
	forn(i, n)
	cin >> v[i];
	unordered_map<int, int> m1, m2;
	m1.reserve(1 << 21);
	m2.reserve(1 << 21);
	store(v, 0, n / 2, m1);
	store(v, n / 2, n, m2);
	for (auto p : m1)
		ans += p.ss * m2[x - p.ff];
	cout << ans << endl;
}
 
signed main()
{
	FIO;
	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; i++)
		solve();
}
