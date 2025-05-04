#include<bits/stdc++.h>
using namespace std;
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("fma")
// #pragma GCC optimization ("unroll-loops")
 
// ordered set in GNU C++
// *(s.find_by_order(2)) : 3rd element in the set i.e. 6
// s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
// using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
using orderedset = tree<T ,null_type,std::less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,n) for(ll i=0;i<(n);i++)
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define ll long long
// #define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define setll set<ll>
#define mapll map<ll,ll>
#define lb lower_bound
#define ub upper_bound
#define prq priority_queue
#define ff first
#define ss second
#define INF LLONG_MAX
// #define INF 100
#define MINF -1e18
const ld PI = 3.14159265358979323846;
#define setBits(x) __builtin_popcount(x)
vll dx={1,0,-1,0};  // down right up left
vll dy={0,1,0,-1};
const int N=1005;
const int M=1000000007;
// const int M=998244353;
ll gcd(ll a, ll b) {  if(b==0)  return a;  return gcd(b,a%b);  }         
ll lcm(ll a, ll b) {  return (a*b)/gcd(a,b) ;  }
bool sortbysec(const pll &a,const pll &b)    {  return (a.second < b.second);  }
bool sortbyfirst(const pll &a,const pll &b)    {  return (a.first < b.first);  }
ll modexp(ll a,ll b){
    int res = 1;
    while (b){if(b%2==1)res= (res*a)%M; b>>=1; a=(a*a)%M;}
    return res%M;
}
ll inv(ll a) { return modexp(a,M-2)%M; }
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
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
 
 
 
void solve(ll tc)
{
	int n; cin>>n;
	vector<vector<int>> adj(n+1);
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	int ans = 0;
	vector<int> dp(n+1,0);
 
	function<bool(int)> isleaf = [&](int node){
		if(node != 1 and adj[node].size() == 1) return true;
		if(node==1 and adj[node].size()==0) return true;
		return false;
	};
 
	function<void(int,int)> dfs = [&](int node, int par){
		if(isleaf(node)){
			dp[node] = 1;
			ans = max(ans, 1);
			return;
		}
 
		for(auto& it: adj[node]){
			if(it==par) continue;
			dfs(it, node);
		}
 
		vector<int> vec;
		for(auto& it: adj[node]){
			if(it==par) continue;
			vec.push_back(dp[it]);
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
 
		dp[node] = vec[0] + 1;
 
		if(vec.size() > 1){
			ans = max(ans, vec[0] + vec[1] + 1);
		}    
		else{
			ans = max(ans, vec[0] + 1);
		} 	
	};
	dfs(1,-1);
 
	cout<<ans - 1<<endl;
 
	return;
}
 
int main()
{
	fast;  
	// sieve();
	// solve_first();
	// init();
	ll tt=1;  
	// cin>>tt;
	ll tc=1;
	while(tc<=tt)
	{
		solve(tc);
		tc++;
	}
	return 0;
}
