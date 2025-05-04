#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define zero_bits __builtin_clzll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(v) (v).rbegin(), (v).rend()
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define si set<int>
#define sl set<ll>
#define mll map<ll,ll>
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define int long long int
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fo(i,n) for(ll i = 0; i < n;i++)
#define UPPER(a) transform(all(a),a.begin(),::toupper)
#define LOWER(a) transform(all(a),a.begin(),::tolower)
#define rits set<int>::reverse_iterator rit
 
 
 
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define pii pair<int,int>
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
void read(vector<int> &a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}
void read(vector<char> &a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}
void read(vector<string> &a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}
void read(vector<vector<int>> &a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			cin >> a[i][j];
}
void read(vector<vector<char>> &a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			cin >> a[i][j];
}
void read(vector<pair<int, int>> &a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i].first >> a[i].second;
}
 
template <class T> void print(T x) {
	cout << x << endl;
}
template <class T> void printArray(vector<T>&a) {
	for (auto it : a) {
		cout << it << " ";
	}
	cout << endl;
}
const int MAX1 = 100005;
const int MAX2 = 200005;
 
/*
    Dynamic Programming , binary search , Segment Tree
    Form Graph , DFS , BFS ,
    Prefix Sum , Greedy
    Reverse
*/
 
struct node {
	int sum;
	int maxPrefixSum;
	node() {
		sum = 0;
		maxPrefixSum = 0;
	}
	node(int val) {
		sum = val;
		maxPrefixSum = val;
	}
};
 
vector<int> a;
vector<node> t;
node merge(node a, node b) {
	node temp;
	temp.sum = a.sum + b.sum;
	temp.maxPrefixSum = max({a.sum + b.maxPrefixSum , a.maxPrefixSum });
	return temp;
}
void build(int id , int l , int r) {
	if (l == r) {
		t[id] = node(a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id , l , mid);
	build(2 * id  + 1 , mid + 1 , r);
	t[id] = merge(t[2 * id]  , t[2 * id + 1]);
}
node query(int id , int l , int r , int lq , int rq) {
	if (r<lq or l>rq) {
		return node();
	}
	if (l >= lq and r <= rq) {
		return t[id];
	}
	int mid = (l + r) / 2;
	return merge(query(2 * id , l , mid , lq , rq) , query(2 * id + 1 , mid + 1 , r, lq , rq));
}
void update(int id , int l , int r, int pos , int val) {
	if (pos<l or pos>r) {
		return;
	}
	if (l == r) {
		t[id] = node(val);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * id , l , mid , pos , val);
	update(2 * id + 1 , mid + 1 , r, pos , val);
	t[id] = merge(t[2 * id] , t[2 * id + 1]);
}
void solve(int tt)
{
	int n , q;
	cin >> n >> q;
	a.resize(n);
	read(a);
	t.resize(4 * n);
	build(1 , 0 , n - 1);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos , val;
			cin >> pos >> val;
			update(1 , 0 , n - 1 , pos - 1 , val);
		}
		else {
			int l , r;
			cin >> l >> r;
			cout << max(query(1 , 0 , n - 1 , l - 1 , r - 1).maxPrefixSum, 0ll) << endl;
		}
	}
 
}
 
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// freopen("r.txt", "w", stderr);
#endif
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	fastio();
	auto start1 = high_resolution_clock::now();
	ll t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
 
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
 
/*
in permutation or after doing some operations we have given some array try to do these problems
in reverse order that most probably you will get the solution of that problem
 
1.) Set.order_of_key(Val) -> this gives the number of integers strictly less than Val in the Set.
2.) Set.find_by_order(k-1) -> this will give the pointer to kth smallest number.
3.) lower bound will point to next greater element if not present in container else on that value
4.) upper bound all points to next greater element
5.) rotate(v.begin(), v.begin()+rotL, v.end()); left rotation
6.) rotate(v.begin(), v.begin()+v.size()-rotR, v.end()); right rotation
 
*/
