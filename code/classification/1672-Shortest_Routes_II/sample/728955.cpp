#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define n_l '\n'
 
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#endif
 
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define forn(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef double db;
typedef vector<vi> vvi;
const ll mod=1000000007;
const ll N=505; //check this
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
 
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powb(ll a,ll b) {ll res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
 
vector<pair<ll,ll>> g[N];
ll dis[N][N];
int n,m,q;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    forn(i,m){
    	ll x,y,d;
    	cin>>x>>y>>d;
    	if(x==y)continue;
    	g[x].pb({y,d});
    	g[y].pb({x,d});
    }
    forn(i,N)forn(j,N)dis[i][j]=LLONG_MAX;
 
    for1(source,n){
	    // dis[source][source]=0;
	    // set<pair<ll,ll>> s;
	    // s.insert({0,source});
	    // while(!s.empty()){
	    // 	ll v = (*s.begin()).se;
	    // 	ll d = (*s.begin()).fi;
	    // 	s.erase(s.begin());
	    // 	for(auto i:g[v]){
	    // 		ll u=i.fi;
	    // 		ll len=i.se + dis[source][v];
	    // 		if(len<dis[source][u]){
	    // 			s.erase({dis[source][u],u});
	    // 			dis[source][u]=len;
	    // 			s.insert({dis[source][u],u});
	    // 		}
	    // 	}
	    // }
    	dis[source][source]=0;
    	vl u(n+1,0);
    	for1(i,n){
    		ll v=-1;
    		for1(j,n){
    			if(!u[j] && (v==-1 || dis[source][j]<dis[source][v]))
    				v=j;
    		}
    		if(dis[source][v]==LLONG_MAX)break;
    		u[v]=1;
    		for(auto e:g[v]){
    			ll to=e.fi;
    			ll len=e.se;
    			if(len+dis[source][v] < dis[source][to]){
    				dis[source][to]=dis[source][v]+len;
    			} 
    		}
    	}
	}
	while(q--){
		int x,y;cin>>x>>y;
		// if(x>y)swap(x,y);
		// assert(dis[x][y]==dis[y][x]);
		if(dis[x][y]==LLONG_MAX)cout<<"-1\n";
		else cout<<dis[x][y]<<"\n";
	}
}
