/*
    SET YOUR HEART ABLAZE
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
 
 
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout<< endl
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const long long inf = 1LL<<62;
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
 
 
 
void solve() {
	int n, m;
	cin >> n >> m;
	int dis[n+1];
	int par[n+1];
	for(int i = 1; i<n+1; i++){
	dis[i] = inf;
	par[i] = 0;
	};
	vector<vi> edges;
	rep(i, 0, m){
		int x, y, w;
		see(x, y, w);
		// gr[x].push_back(y);
		edges.pb({x, y, w});
	}
	dis[1] = 0;
	int f ;
	for(int i = 0 ; i<n; i++){
		f = 0;
			for(auto x: edges){
				if(dis[x[0]]+x[2]<dis[x[1]]){
					dis[x[1]] = dis[x[0]]+x[2];
					par[x[1]] = x[0];
					f = x[1];
				}
			}			
	}
	if(!f){putl("NO");return;}
	else{
        putl("YES");
        vi cyc;
        rep(i,1,n+1) f = par[f];
        for (int x = f;; x = par[x]){
            cyc.pb(x);
            if (x==f && cyc.sz>1) break;
        }
        
        reverse(all(cyc));
        for (auto i: cyc) put(i);
    }}
 
// SOLVE
 
 
signed main()
{
	IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}
