// Author: Akshay A Baiju
// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Problem tag:
// TC:
// SC:
 
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector <int>
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define rrep(i,n,a) for (int i=n;i>=a;i--)
#define fill1(a,x) for (auto &it: a) it=x;
#define fill2(a,x) for (auto &v: a) { for (auto &it: v) it=x; }
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define YY cout<<"YES"
#define NN cout<<"NO"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define endl "\n"   //not to be used in interactive problems
#define random(l,r,T) uniform_int_distribution<T>(l,r)(rng)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define oset tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> // find_by_order, order_of_key
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#ifndef ONLINE_JUDGE
	#define debug(x)	    cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
	#define debug(x)
#endif
 
const int M = 1e9+7;
const int MOD = 998244353;
const int N = 1e5+7;
const ll inf = 1e18;
const ld eps = 1e-6;
 
int dx[]={0,1,0,-1};	//{0,1,1,1,0,-1,-1,-1};
int dy[]={1,0,-1,0};	//{1,1,0,-1,-1,-1,0,1};
 
void _print(ll t) { cerr<<t; }
void _print(int t) { cerr<<t; }
void _print(ld t) { cerr<<t; }
void _print(string t) { cerr<<t; }
void _print(char t) { cerr<<t; }
 
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}
 
ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll binExp(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=M) { a = a % m; return binExp(a,m-2,m); }		// only for prime m
ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
 
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <class T, class H> using umap=unordered_map<T,H,custom_hash>;
template <class T> using uset=unordered_set<T,custom_hash>;
 
void dfs(ll x, ll y, vector <string> &grid, vector <vbool> &vis)
{
	ll n=grid.size();
	ll m=grid[0].size();
	if (x<0 || x>=n || y<0 || y>=m || grid[x][y]=='#' || vis[x][y]) return;
	vis[x][y]=true;
	for (ll i=0;i<4;i++)
	{
		ll newx=x+dx[i];
		ll newy=y+dy[i];
		dfs(newx,newy,grid,vis);
	}
}
 
void solve()
{
	ll n,m; cin>>n>>m;
	vector <string> grid(n); cin>>grid;
	vector <vbool> vis(n, vbool (m,false));
	ll cc=0;
	for (ll i=0;i<n;i++)
	{
		for (ll j=0;j<m;j++)
		{
			if (grid[i][j]=='.' && !vis[i][j])
			{
				cc++;
				dfs(i,j,grid,vis);
			}
		}
	}
	cout<<cc;
}
 
int main()
{
	#ifndef ONLINE_JUDGE
		// freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
		// freopen("error.txt","w",stderr);
		clock_t clk = clock();
	#endif
	sync;
	int t=1;
	// cin>>t;
	for (int test=1;test<=t;test++)
	{
		// cout<<"Case #"<<test<<": ";
		solve();
		cout<<endl;
	}
	#ifndef ONLINE_JUDGE
		cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif
	return 0;
}
