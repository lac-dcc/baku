#include<bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order , order_of_key
// greater<int> -> decending order , less_equal<int> -> multiset ascending , greater_equal
// *s.find_by_order(x) -> element at index x (0 based) , s.order_of_key(x) -> no of element less than x
#define int long long int
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define INF INT_MAX
#define forin for(int i=0;i<n;i++)
#define forjm for(int j=0;j<m;j++)
#define rep(i,x,y) for(int i=x; i<y; i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define pii pair<int,int>
#define vvpii vector<vector<pair<int,int>>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpii vector<pair<int,int>>
#define vvvi vector<vector<vector<int>>>
 
#define gcd __gcd
#define endl '\n'
#define PI acos(-1)
#define lead_zer __builtin_clzll
#define trail_zer __builtin_ctzll
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
void pre_process() {
	ios_base::sync_with_stdio(false); // comment out if interactive
	cin.tie(NULL); cout.tie(NULL);  // comment out if interactive
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
}
 
vector<pair<int, int>> movements = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
const int M = 1e9 + 7;
const int N = 1e5 + 10;
 
int dfs(int node, vvi &g, int &diameter, int parent = -1) {
 
	multiset<int> dist;
	debug(node);
	for (auto child : g[node]) {
		if (parent == child) continue;
		debug(child);
 
		dist.insert(dfs(child, g, diameter, node));
	}
 
	if (dist.size() == 0) return 0; // leaf node
 
	if (dist.size() >= 2) {
		//debug(dist);
		diameter = max(diameter, *prev(dist.end(), 1) + *prev(dist.end(), 2) + 2);
	}
 
	if (dist.size() >= 1) {
		diameter = max(diameter , * prev(dist.end(), 1) + 1);
	}
	//return 0;
	return 1 + *prev(dist.end(), 1);
 
}
 
void solve() {
	int n;
	cin >> n;
	vvi g(n);
 
	rep(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
 
	debug(g);
	int diameter = 0;
 
	dfs(0, g, diameter);
 
	cout << diameter;
}
int32_t main() {
	pre_process();
	solve();
	return 0;
}
 
