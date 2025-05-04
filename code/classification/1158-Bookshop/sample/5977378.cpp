						#include <bits/stdc++.h>
						#include <chrono> 
						 
						using namespace std;
						using namespace std::chrono; 
						 #define n1 "\n"
						#define st string
						#define NF st::npos	
						// 
						// #pragma GCC optimization ("O3")
						// #pragma GCC optimization ("unroll-loops")
						// #pragma optimization_level 3
						// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
						// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
						#define unique(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
						#define rep(a, b) for (long long a = 0; a < (b); ++a)
						#define rep1(i,n) for(long long i=1;i<=n;i++)
						#define per(i,n) for(long long i=(ll)(n)-1;i>=0;i--)
						#define per1(i,n) for(long long i=n;i>=1;i--)
						#define Rep3(i,sta,n) for(long long i=sta;i<=n;i++)
						#define rep3(a, b, c) for (long long a = (b); a < (c); ++a)
						#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
						#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
						#define ms(arr, v) memset(arr, v, sizeof(arr))
						#define pb push_back
						# define pf push_front 
						# define ppb pop_back           // used to delete elemets in vector from backwards
						# define ppf pop_front 
						#define MP make_pair
						#define ff first
						#define ss second
						#define all(a) a.begin(), a.end()
						# define rall(a) (a).rbegin(), (a).rend() 
						# define sz(a) ((int)(a).size())
						# define lb lower_bound                      // algorithms
						# define ub upper_bound   
 
						#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
						#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
						#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
						#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
						#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
						#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
						#define vsz(x) ((long long) x.size())
						typedef long long ll;
						typedef double ld;
						typedef long double lld;
						typedef unsigned long long ull;
						typedef pair<int, int> pii;
						typedef pair<ll, ll> pll;
						typedef vector<int> vi;
						typedef vector<ll> vl;
						typedef vector<pii> vpi;
						typedef vector<pll> vpl;
						# define br break                       //breaks the statement 
						# define rt return 
						# define cn continue
						# define nl "\n"
						# define off exit(0)
				#define endl "\n"
						#define lcm(a,b) (a*(b/__gcd(a,b)))
						#define hcf(a,b)  (a*(b/__gcd(a,b)))
						#define max3(a,b,c) max(a,max(b,c))
						#define min3(a,b,c) min(a,min(b,c))
						  
						#define eb   emplace_back
						 // STL Algorithms
						#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
						#define mine(a)    (*min_element((a).begin(), (a).end()))
						#define maxe(a)    (*max_element((a).begin(), (a).end()))
						#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
						#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
						#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
						#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
 
 
						template<typename T>
						void chmin(T& a, T b) {
							a = min(a, b);
						}
						template<typename T>
						void chmax(T& a, T b) {
							a = max(a, b);
						}
						template<typename T>
						void cinarray(vector<T>& v) {
							rep(i, v.size())cin >> v[i];
						}
						template<typename T>
						void coutarray(vector<T>& v) {
							rep(i, v.size()) {
								if (i > 0)cout << " "; cout << v[i];
							}
							cout << "\n";
						}
 
					void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
					void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
					void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
 
						// template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
						// template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
						// template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
						// template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
						// template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
						// template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
						// template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
						// template<typename T, typename U> ostream& operator<<(ostre4am& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
						// template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
						// template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
						// template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
						// template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
 
 
 
						 
						#ifdef HOME
						#define SHOW_COLORS
						#include "/mnt/c/Libs/tools/print.cpp"
						#else
						#define show(...) void(0)
						#define debugf(fun)   fun
						#define debugv(var)   var
						#define mclock    void(0)
						#define shows     void(0)
						#define debug  if (false)
						#define OSTREAM(...)    ;
						#define OSTREAM0(...)   ;
						#endif
 
						 
 
						 
						mt19937 rng(steady_clock::now().time_since_epoch().count());
						// mt19937 rng(61378913);
						/* usage - just do rng() */
						 
				        
					
						const ll MAXN = 2e5 + 25;
						const ll MAXL = 18 + 0;
						const ll INF = 1e18 + 0;
						const ll inf = 2e9 + 0;
						const ll M = 1e9 + 7;
						const ll mod = 998244353;
						const ld PI = acos( (ld) -1 );
						const ll P = 67 + 0 + 0;
						int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
						int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
						  
						namespace modop {
							ll madd(ll a, ll b) {
							  return (a + b) % mod;
							}
							ll msub(ll a, ll b) {
							  return (((a - b) % mod) + mod) % mod;
							}
							ll mmul(ll a, ll b) {
							  return ((a % mod) * (b % mod)) % mod;
							}
							ll mpow(ll base, ll exp) {
							  ll res = 1;
							  while (exp) {
								if (exp % 2 == 1){
									res = (res * base) % mod;
								}
								exp >>= 1;
								base = (base * base) % mod;
							  }
							  return res;
							}
							ll minv(ll base) {
							  return mpow(base, mod - 2);
							}
							ll mdiv(ll a, ll b) {
							  return mmul(a, minv(b));
							}
						}
 
						ll binexp(ll a, ll b){
							if(b == 0) return 1;
							ll res = binexp(a, b/2);
							res %= M;
							if(b&1) return a* res * res; //(%m)
							else return res * res;
						}
 
						#define rrep(x, l, u) for (ll x = l; x >= u; x--)
						using namespace modop;
 
						// ll n, m, k, q, l, r, x, y, z;
						// ll a[1000005];
						// ll b[1000005];
						// ll c[1000005];
						// string s, t;
						// ll ans = 0;
				#define each(a, x) for (auto &a : x)
 
						void open (string fname = "")
						{
						    if (fname.size())
						    {
						        freopen((fname + ".in").c_str(), "r", stdin);
						        freopen((fname + ".out").c_str(), "w", stdout);
						    }
						}
						void qataima ()
						{
						    ios::sync_with_stdio(false);
						  
						    cin.tie(0);                                                                                                            
						    
							//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
						}
 
						//#define rep(i,j,k) for(ll i=j;i<k;i++)
			  const int intmax = 2147483647;
 
		// void dfs(int currentNode, vector<vector<int>>& adj, int parent, vector<int>& ans){
		// 	ans.push_back(currentNode);
		// 	//vis[currentNode] = true;
		// 	for(int neighbour : adj){
		// 		if(neighbour!= parent) 
		// 			dfs(neighbour, adj, currentNode, ans);
		// 	}
 
 
		// }
 
      // ordered ways distinct
   
	   void ma1n (){
	   int n, x;
	   cin >> n >> x;
	   vector<int> a(n);
	   ai(a,n);
	   vector<int> b(n);
	   ai(b,n);
      vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
      for(int i = 1; i<=n; ++i)
      	for(int j = 0; j <=x; ++j){
         dp[i][j] = dp[i-1][j];
         if(j - a[i-1] >= 0)
         	dp[i][j] = max(dp[i][j], dp[i-1][j-a[i-1]]+ b[i-1]);
 
      	}
 
      	cout << dp[n][x];
 
	}
	
  
    
        
 
       
 
 
 
 
 
 
						int main ()
						{  
							qataima ();
						    open ();
						    int zxc = 1;
							//cin >> zxc;
						    while (zxc--)	
						    {	
						        ma1n();
						 
						}
						}
 		  
 		   
 
 
		//    vector<vector<int>> adj(n);
		//    for(int i = 0; i< n-1; ++i){
		//    int u,v;
		//    cin >> u >> v;
		//    u--, v--;
		//    adj[u].push_back(v);
		//    adj[v].push_back(u);
		// }
		// // BFS
		// int root = 0;
		// vector<int> bfs_traversal;
		// queue<int> qu;
		// vector<bool> visited(n, false);
		// qu.push(root);    // push the root
		// visited[root] = true;       // root has been visited
		// while(!(qu.empty())){
		// 	int currentNode = qu.front();
		// 	qu.pop();        
		// 	bfs_traversal.push_back(currentNode);
		// 	for(int neighbour : adj[currentNode]){
		// 		if(!visited[neighbour]){
		// 			visited[neighbour] = true;
		// 			qu.push(neighbour);
		// 		}
		// 	}
		// }