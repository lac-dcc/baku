//{ Header
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define vi vector<int>
#define vd vector<double>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define fin(ar,k,n) for(int i=k;i<n;i++) cin>>ar[i]
#define fout(ar,k,n) for(int i=k;i<n;i++) cout<<ar[i]<<' '
#define all(z) z.begin(),z.end()
#define mcc ((int)1e9+7)
#define mcf 998244353
#define eps 1e-9
#define mi map<int,int>
#define mem(a,n) memset(a,n,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define eb(x) emplace_back(x)
#define min_heap(T) priority_queue<T,vector<T>,greater<T>>
#define max_heap(T) priority_queue<T>
 
using namespace std;
using namespace std::chrono; 
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> fst;
 
void print(){}
template <typename T, typename... Types>
void print(T var1, Types... var2){cout << var1; print(var2...) ;}
 
void printn(){cout<<'\n';}
template <typename T, typename... Types>
void printn(T var1, Types... var2){cout << var1; printn(var2...) ;}
 
 
void read(){}
template <typename T,typename... Types>
void read(T& var1, Types&... var2){cin>>var1; read(var2...);}
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cerr << H << " "; dbgs(T...); } 
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cerr << endl;
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
//}
 
// use as LSTree<type> name(size);
template <typename T>
class LSTree{
	private:
		int N; 
		vector<T> ar, lazy; 
		T U=-1e18;
		T F(T x, T y) { return max(x,y); } 
		void pull(int i) { ar[i] = F(ar[i*2],ar[i*2+1]); }
		void push(int i, int l, int r) {
			ar[i]+=lazy[i];
			if(l!=r) lazy[i*2]+=lazy[i], lazy[i*2+1]+=lazy[i];
			lazy[i]=0; 
		}		
		
	public:
		LSTree() {}
		LSTree(int N) : N(N), ar(4*(N+1),U), lazy(4*(N+1),0) {}			
		void make(vector<T> &v) { make(v,1,0,N); }
		void make(vector<T> &v, int i, int l, int r) {
			if(l==r) { ar[i]=v[l]; return; } 
			int m=(l+r)/2;
			make(v,i*2,l,m); make(v,i*2+1,m+1,r); pull(i);
		}
 
		void upd(int L, int R, T v) { upd(L,R,v,1,0,N); }
		void upd(int L, int R, T v, int i, int l, int r) {
			push(i,l,r); if(R<l || L>r) return;
			if(L<=l && R>=r) { lazy[i]+=v; push(i,l,r); return; }
			int m=(l+r)/2; upd(L,R,v,i*2,l,m);
			upd(L,R,v,i*2+1,m+1,r); pull(i);
		}
 
		T get(int L, int R) { return get(L,R,1,0,N); }
		T get(int L, int R, int i, int l, int r) {
			push(i,l,r); if(R<l || L>r) return U;
			if(L<=l && R>=r) return ar[i]; 
			int m=(l+r)/2;
			return F(get(L,R,i*2,l,m), get(L,R,i*2+1,m+1,r));
		}		
};
 
LSTree<ll> st;
 
void solve(){	
	ll n,q,c,a,b;
	read(n,q);
	vl ar(n+1),pre(n+1);
	fin(ar,1,n+1);
	st=LSTree<ll>(n+1);
	for (ll i= 1; i<=n; ++i) pre[i]=pre[i-1]+ar[i];
	st.make(pre);		
	while (q--){
		read(c,a,b);
		if (c==1){			
			st.upd(a,n,b-ar[a]);
			ar[a]=b;
		}
		else{			
			printn(st.get(a-1,b)- st.get(a-1,a-1));
		}		
	}
}
 
//{ Tail
int main()
{
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("debug.txt","w",stderr);
    #endif
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start); 
	cerr<<"Main Execution (in ms.): "<< 1.0*duration.count()/1000 << endl; 
    return 0;
}
//}