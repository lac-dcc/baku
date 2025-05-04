//Input Output
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<streambuf>
//C lib
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cctype>
//Container
#include<array>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
//Others
#include<tuple>
#include<algorithm>
#include<functional>
#include<numeric>
#include<iterator>
#include<limits>
#include<utility>
#include<complex>
#include<type_traits>
#include<initializer_list>
#include<random>
 
using namespace std;
 
#if __cplusplus > 201703L
#include<concepts>
#include<ranges>
#include<bit>
#include<numbers>
using namespace numbers;
#include<span>
#endif
 
void _debug() {cerr << '\n';}
template <typename A, typename... B>
void _debug(A a, B... b) {cerr << a << ' ', _debug(b...);}
#define debug(...) cerr << '(' << (#__VA_ARGS__) << ") : ", _debug(__VA_ARGS__)
 
namespace abb {
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
template<size_t s> using B = bitset<s>;
template<typename T> using V = vector<T>;
template<typename T> using Q = queue<T>;
template<typename T> using DQ = deque<T>;
template<typename T> using V2d = vector<vector<T>>;
template<typename T> using US = unordered_set<T>;
template<typename T, size_t s> using A = array<T, s>;
template<typename T1, typename T2> using UM = unordered_map<T1, T2>;
template<typename T1, typename T2 = T1> using P = pair<T1, T2>;
template<typename T, typename Cmp = less<T>> using S = set<T, Cmp>;
template<typename T, typename Cmp = less<T>> using PQ = priority_queue<T, V<T>, Cmp>;
template<typename T1, typename T2, typename Cmp = less<T1>> using M = map<T1, T2, Cmp>;
template<typename T> using F = function<T>;
}
 
namespace output {
template<typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
 
#define unfold1(Container) \
template<typename T> \
inline ostream& operator<<(ostream& os, const Container<T>& x) { \
    for (const auto& i : x) \
        os << i << ' '; \
    return os; \
}
#define unfold2(Container) \
template<typename T1,typename T2> \
inline ostream& operator<<(ostream& os,const Container<T1,T2>& x){ \
    for (const auto& i : x) \
        os << i << ' '; \
    return os; \
}
unfold1(vector); unfold1(set); unfold1(deque); unfold2(map)
#undef unfold1
#undef unfold2
};
 
namespace rit {
struct fast_istream {
    operator bool() const {return bool(cin);}
    fast_istream() {cin.tie(nullptr);}
} fin;
#if __cplusplus > 201703L
template<typename T>
fast_istream& operator>>(fast_istream& is, T& n) requires integral<T> {
#else
template<typename T, class = typename enable_if<is_integral<T>::value>::type>
fast_istream & operator>>(fast_istream& is, T& n) {
#endif
    while (isspace(cin.rdbuf()->sgetc()))
        cin.rdbuf()->snextc();
    bool sign = false;
    if (cin.rdbuf()->sgetc() == '-')
        sign = true, cin.rdbuf()->snextc();
    for (n = 0; isdigit(cin.rdbuf()->sgetc());)
        n *= 10, n += cin.rdbuf()->sbumpc() - '0';
    n = sign ? -n : n;
    return is;
}
fast_istream& operator>>(fast_istream& is, char& n) {
    while (isspace(cin.rdbuf()->sgetc()))
        cin.rdbuf()->snextc();
    n = cin.rdbuf()->sbumpc();
    return is;
}
}
 
#define endl '\n'
namespace wit {
struct fast_ostream {
    operator bool() const {return bool(cout);}
    fast_ostream() {cout.tie(nullptr);}
} fout;
constexpr int buffer_size = 30;
#if __cplusplus > 201703L
template<typename T>
fast_ostream& operator<<(fast_ostream& os, T n) requires integral<T> {
#else
template<typename T, class = typename enable_if<is_integral<T>::value>::type>
fast_ostream & operator<<(fast_ostream& os, T n) {
#endif
    if (!n) {cout.rdbuf()->sputc('0'); return os;}
    if (n < 0) cout.rdbuf()->sputc('-'), n = -n;
    static char buffer[buffer_size];
    int cnt = buffer_size;
    for (; n; n /= 10)
        buffer[--cnt] = n % 10 + '0';
    cout.rdbuf()->sputn(buffer + cnt, buffer_size - cnt);
    return os;
}
fast_ostream& operator<< (fast_ostream& os, const char& n) {
    cout.rdbuf()->sputc(n); return os;
}
}
//#define MULTI_TASKCASE
using namespace rit;
using namespace wit;
using namespace abb;
using namespace output;
 
inline void init() {
 
}
 
constexpr int maxn=2e5+5;
struct node{
	ll sum, lmax, rmax, submax;
	node(ll a=0,ll b=0,ll c=0,ll d=0):
	sum(a),lmax(max(0LL,b)),rmax(max(0LL,c)),submax(max(0LL,d)){}
} arr[(maxn+1)<<2];
inline node pull(node a,node b){
	return node(
		a.sum+b.sum,
		max(a.lmax,a.sum+b.lmax),
		max(b.rmax,b.sum+a.rmax),
		max({a.submax,b.submax,a.rmax+b.lmax})
	);
}
ostream& operator<<(ostream& os,node a){
	return os<<'('<<a.sum<<','<<a.lmax<<','<<a.rmax<<','<<a.submax<<')'<<' ';
}
 
#define m ((l+r)>>1)
void build(V<ll>& v,int i=1,int l=0,int r=maxn){
	if(r-l==1){if(l<int(v.size())) arr[i]=node(v[l],v[l],v[l],v[l]);return;}
	build(v,i<<1,l,m),build(v,i<<1|1,m,r);
	arr[i]=pull(arr[i<<1],arr[i<<1|1]);
}
node query(int ql,int qr,int i=1,int l=0,int r=maxn){
	if(qr<=l||r<=ql) return node();
	if(ql<=l&&r<=qr) return arr[i];
	return pull(query(ql,qr,i<<1,l,m),query(ql,qr,i<<1|1,m,r));
}
void update(int p,ll k,int i=1,int l=0,int r=maxn){
	if(p<l||r<=p) return;
	if(r-l==1){arr[i]=node(k,k,k,k);return;}
	update(p,k,i<<1,l,m),update(p,k,i<<1|1,m,r);
	arr[i]=pull(arr[i<<1],arr[i<<1|1]);
}
#undef m
 
inline void solve() {
	int n,m; cin>>n>>m;
	V<ll> v(n);
	for(auto& i:v)
		cin>>i;
	build(v);
	while(m--){
		int p,k; cin>>p>>k,p--;
		update(p,k);
		cout<<query(0,n).submax<<endl;
	}
}
 
//1 6 -3 5 -1
//1 6 1 5 -1
//1 -2 1 5 -1
 
 
signed main() {
    ios::sync_with_stdio(false);
    init();
    int t = 1;
#ifdef MULTI_TASKCASE
    cin >> t; cin.ignore();
#endif
    while (t--) solve();
    return 0;
}
