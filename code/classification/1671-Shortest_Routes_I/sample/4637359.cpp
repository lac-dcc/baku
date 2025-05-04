// Author -> AMAN PANDEY
 
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define need_for_speed      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int                 long long 
#define dl                  '\n'
#define ll                  long long 
#define ld                  long double
#define pb                  push_back
#define ppb                 pop_back()
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define setbits(x)          __builtin_popcountll(x)
#define inf                 9e18
#define PI                  3.14159265358979323846 
#define ub                  upper_bound
#define lb                  lower_bound
#define pii                 pair<int,int>
#define mii                 map<int,int>
#define vi                  vector<int>
#define vpi                 vector<pair<int,int>>
#define vvi                 vector<vector<int>> 
#define maxheap(x)          priority_queue<x>
#define minheap(x)          priority_queue<x,vector<x>,greater<x>>
#define maxe(x)             *max_element(all(x))
#define mine(x)             *min_element(all(x))
#define si(x)               (int)x.size()
#define uset                unordered_set<int>
#define uii                 unordered_map<int,int>
#define present(a,b)        a.find(b)!=a.end()
#define ff                  first
#define ss                  second
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define Yes                 cout << "Yes\n";
#define No                  cout << "No\n";
#define imp                 cout << "IMPOSSIBLE\n";
#define acc(x)              accumulate(all(x),0ll)
#define fo(i,b)             for(ll i=0;i<b;i++)
#define tr(it, a)           for(auto it = a.begin(); it != a.end(); it++)
#define read(v)             for(auto &itt:v) cin>>itt;
#define rep(x,start,end)    for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define case(i)             cout<<"Case #"<<i++<<": ";
#define uniq(v)             (v).erase(unique(all(v)),(v).end())
#define concat(i,j)         i##j
#define rightmostsetbit(x)  x&-x
#define re                  return
#define ba                  back()
#define mem1(a)             memset(a,-1,sizeof(a))
#define mem0(a)             memset(a,0,sizeof(a))
#define mem(i,n,m)          i.resize(n+2,vector<int>(m+2,-1));
#define rz                  resize
#define gcd(a,b)            __gcd(a,b)
#define ppc                 __builtin_popcount
#define ppcll               __builtin_popcountll
#define trailingzll         __builtin_ctzll
#define leadingzll          __builtin_clzll  
 
#define mod                1000000007
//define mod                998244353   
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order
// order_of_key(k) :returns number of items < k
// find_by_order(k):returns iterator to kth element(0-based)
 
inline long long ceil_div(long long a, long long b) { return a / b + ((a ^ b) > 0 && a % b); } 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template <typename T1, typename T2> 
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p){return (ostream << p.first << " " << p.second);}
template <typename T> 
ostream &operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c)cout << it << " ";return ostream;}
template <typename T>void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>void print(T &&t, Args &&...args){cout << t << " ";print(forward<Args>(args)...);}
template <typename T> int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }
enum color {white, gray, black};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
 
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
const double EPS=1e-9; 
ll expo(ll a, ll b, ll m=mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
int fast_pow(int a, int p) { int res = 1; while (p) { if (p % 2 == 0) { a = a * 1ll * a % mod; p /= 2; } else { res = res * 1ll * a % mod; p--;}} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll isprime(ll n){ if(n<=1) return 0; if(n<=3) return 1; if(n%2==0||n%3==0) return 0; for(ll i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) return 0; return 1; }
ll power(ll a , ll n){if(n==0) return 1;if(n==1) return a;if(n&1)  return (a%mod * power(a,n-1)%mod)%mod ;else     return power((a*a)%mod ,n/2)%mod ;}
int primeFactors(int n){int ans=0;if(n%2==0)ans++;while(n%2==0){n=n/2;}for(int i=3;i<=sqrt(n);i=i+2){if(n%i==0)ans++;while(n%i==0){n=n/i;}}if(n>2)ans++;return ans;} 
int LIS(vi &a){vi lis;for(auto &x:a){auto it=upper_bound(all(lis),x);if(it==lis.end()) lis.pb(x); else *it=x;} return si(lis);}
bool isperfect(ll n){ if(n>=0){ ll a=sqrt(n);return (a*a==n);}return false;}
void sieve(vi &prime){int n=si(prime);prime[0]=prime[1]=0;for(int i=2;i*i<=n;i++){if(prime[i]){for(int j=i*i;j<=n;j+=i)prime[j]=0;}}}
int fact(int n) { int res = 1; for (int i = 1; i <= n; i++) { res = res * 1ll * i % mod;} return res;}
int ncr(int n, int k) { if(n<k) return 0; if(k==0) return 1; return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod; }
int lcm(int a,int b){return a*b/__gcd(a,b);}
int manhattan_distanceint(pii a,pii b){return (a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss);}
int dcmp(ld x,ld y){ return fabs(x-y)<EPS?0:x>y?1:-1;}
ld manhattan_dis(double x,double y,double xx,double yy){ return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy)); }
 
 
#define wh int x=1; \
        //cin>>x;     \
        while(x--)  
#define prec(n) fixed << setprecision(n)
    
 
const double eps=1e-9;
const int mxN=2e5 + 10;
const int N=1e5+10;
 
int n,m;
vpi g[N];
int dis[N];
 
void dijkstra(int s){
	for(int i=0;i<n;i++) 
		dis[i]=1e18;
	
	minheap(pii) pq;
	pq.push({0,s});
	dis[s]=0;
	
	while(!pq.empty()){
		pii cur=pq.top(); 
		pq.pop();
		
		if(cur.ff!=dis[cur.ss]) continue;
		
		for(pii it:g[cur.ss]){
			if(cur.ff+it.ss<dis[it.ff]){
				dis[it.ff]=cur.ff+it.ss;
				pq.push({dis[it.ff],it.ff});
			}
		}
		
	}
	
}
 
void AMAN_PANDEY(){
	
	cin >> n >> m;
	
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		g[a].pb({b,c});
	}
	
	dijkstra(0);
	
	for(int i=0;i<n;i++)
		cout << dis[i] << ' ';
 
 
    
}
 
int32_t main(){
    
    need_for_speed  
    
  
    wh{ AMAN_PANDEY(); }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << " ms\n";
    
    return 0;
}
