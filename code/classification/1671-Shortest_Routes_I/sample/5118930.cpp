#include<bits/stdc++.h>
 
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
// #define INF 1e18
#define nline "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
const int MAX_N = 2e5 + 1;
const int INF = 1e9;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
ll X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
ll Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
 
bool prime_check(int n) { 
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
 
void solve() {
	
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll,ll>>> adj(n);
	vector<int> vis(n,0);
	vector<ll> dist(n,LLONG_MAX);
 
	while(m--){
		ll u ,v, wt;
		cin >> u >> v >> wt;
		u--,v--;
		adj[u].push_back({v,wt});
	}
 
 
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
	q.push({0,0});
	dist[0] = 0;
 
	while(!q.empty()){
		ll node = q.top().ss;
		ll dis = q.top().ff;
		q.pop();
		if(vis[node]) continue;
		vis[node] = 1;
 
		for(auto it:adj[node]){
			ll wt = it.ss;
			ll adjNode = it.ff;
 
			if(dis + wt < dist[adjNode]){
				dist[adjNode] = dis + wt;
				q.push({dist[adjNode],adjNode});
			}
		}
	}
 
	// _print(dist);
	for(auto it: dist){
		cout << it << " ";
	}
	// _print(adj);
 
}
 
 
 
 
 
int main(){
	fastio(); 
 
	int tc;tc = 1;
	// cin >> tc;
	while(tc--) solve();
 
	
 
}
