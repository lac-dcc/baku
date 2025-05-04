#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//
//    #pragma GCC optimize("-O3")
//    #pragma GCC optimize("no-stack-protector")
//    #pragma GCC optimize("fast-math")
//    #pragma GCC optimize("Ofast")
//    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//    #pragma GCC target("fma")
//    #pragma GCC optimization ("unroll-loops")
//#define LOCAL
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fi first
#define f first
#define se second
#define s second
#define vi_a vector<int>a;
#define p_b push_back
////////////////////////////////???????????????CHECK THIS OUT???????????????//////////////////////////////
#define ll long long
typedef unsigned long long ull;
////////////////////////////////???????????????CHECK THIS OUT???????????????//////////////////////////////
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define ar array
#define fast_io cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(),x.end()
#define getfiles    ifstream cin("input.txt");ofstream cout("output.txt");
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define endl "\n"
#define rall(x) x.rbegin(),x.rend()
#define len(a) (ll)a.size()
#define rep(x,l,r) for(ll x=l;x<r;x++)
 
using namespace __gnu_pbds;
ld eps = (ld)1 / 1e6;
const ld pi=3.14159265359;
ll inf = 1e18,mod1=1e9+7;
ll sqr(ll a) { return a * a; }
ll qb(ll a) { return a * a * a; }
template<typename T> bool umax(T& a, T b) {return a<b?a=b,1:0;}
template<typename T> bool umin(T& a, T b) {return b<a?a=b,1:0;}
bool is_prime(ll val){for(ll i=2;i<=sqrt(val);i++)if(val%i==0)return 0; return 1;}
ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll binpow(ll a, ll b, ll mod) { return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod : sqr(binpow(a, b / 2, mod)) % mod) : 1; }ll binmult(ll a, ll b, ll mod) { return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod : (2 * binmult(a, b / 2, mod)) % mod) : 0; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const ll RR=1e4;
const ll tx[8]={1,-1,2,-2,-1,-2};
const ll ty[8]={-2,-2,-1,-1,2,1};
const char rev_to[4]={'E','W','N','S'};
const int M=1e9+7;
const int N=1e6+9;
const int ppp=73;
const int pr=3;
const int block=600;
const int OPEN=-1;
const int CLOSE=0;
const int QUERY=1;
typedef pair<long long,int> pli;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> o_st;
auto rnd=bind(uniform_int_distribution<ll>(1,596969),mt19937(time(0)));
void bad(){
    cout<<"-1";
    exit(0);
}
//vector<pii>g[N];
int n,m;
ll dst[2][N];
vector<pii>g[N];
signed main()
{
    fast_io;
    cin>>n>>m;
    for(int i=0;i<2;i++) for(int j=1;j<=n;j++) dst[i][j]=inf;
    for(int i=0;i<m;i++){
        int v,u,c;
        cin>>v>>u>>c;
        g[v].p_b({u,c});
    }
    int s=1,e=n;
    dst[0][s]=0;dst[1][s]=0;
    priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>>pq;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto c=pq.top();
        pq.pop();
        int v=c[1],tp=c[2];
        ll cost=c[0];
        if(dst[tp][v]<cost) continue;
        for(auto &z : g[v]){
            if(tp==0){
                if(dst[0][z.f]>(cost+z.s)){
                    dst[0][z.f]=cost+z.s;
                    pq.push({cost+z.s,z.f,0});
                }
                if(dst[1][z.f]>(cost+(z.s/2))){
                    dst[1][z.f]=(cost+(z.s/2));
                    pq.push({cost+(z.s/2),z.f,1});
                }
            }else{
                if(dst[1][z.f]>(cost+z.s)){
                    dst[1][z.f]=cost+z.s;
                    pq.push({cost+z.s,z.f,1});
                }
            }
        }
    }
    cout<<min(dst[0][e],dst[1][e]);
    return 0;
}
/*
 
*/