/* Omhari */
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std; 
//------------------------------------Define------------------------------------------------------
#define F               first
#define S               second
#define int             long long // Warning
#define ll              long long
#define ull             unsigned long long
#define db              long double
#define ST              string
#define NA              ST::npos //Not found in string
#define pb              push_back
#define Pb              pop_back
#define mp              make_pair
#define el              "\n"
#define vi              vector <int>
#define vt              vector
#define pii             pair <int, int>
#define mii             map<int, int>
#define NF(v)           v.end()
#define sz(v)           (ll)(v.size())
#define all(v)          v.begin(), v.end() 
#define rall(v)         v.rbegin(), v.rend() 
#define is_sort(v)      is_sorted (all(v))
#define max_of(v)       *max_element (all(v))
#define min_of(v)       *min_element (all(v))
#define itos(s)         to_string(s)
#define cntone(x)       __builtin_popcountll(x) // 64-bit
#define cntzro(x)       __builtin_clzll(x)      // 64-bit
#define clr(x,y) 	    memset(x, y, sizeof(x))
#define fil(x,y) 	    fill(all(x), y)
#ifdef  Omhari
#define deb(x)          cerr<<#x<<" = "; dprint(x); cerr<<endl;
#else
#define deb(x);
#endif
#define For(i, a, b)    for(int i=a; i<b; i++)
#define Forr(i, a, b)   for(int i=a; i>=b; i--)
#define Foo(it, box)    for(auto &it:box)
#define OK(l, r, val)   assert(l<=val && val<=r)
#define FAST            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//ordered_set s;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// template<typename T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
//------------------------------------------------------------------------------------------------
//-------------------------------------Constant---------------------------------------------------
const db PI = acos(-1.0);
const ll mod = 1e9+7;
const ll mod1 = 998244353;
const int inf = INT_MAX>>1;
const ll oo = LLONG_MAX>>1;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
//                {R, L, U, D, RD, RU, LU, LD}
//------------------------------------------------------------------------------------------------
//------------------------------------Functions---------------------------------------------------
void IO(){  
    #ifdef Omhari
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    }
void _Time(int64_t duration){
    #ifdef Omhari
    cerr << "Time: " << duration<< " ms" << endl;
    #endif
    }
 
// IncStackSize();
 
// #include <sys/resource.h>
// void IncStackSize()
// {
//     rlimit R;
//     getrlimit(RLIMIT_STACK, &R);
//     R.rlim_cur = R.rlim_max;
//     setrlimit(RLIMIT_STACK, &R);
// }
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll A, ll B) {return uniform_int_distribution<ll>(A, B)(rng);}
ll nCr(ll n, ll r) { if(n<r) return 0; ll ans=1; if(r>n-r) r=n-r; 
for(ll i=1; i<=r; i++) ans*=(n-i+1), ans/=i; return ans;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
inline ll addM(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
inline ll subM(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
inline ll mulM(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
inline ll powM(ll a, ll b, ll m) { ll ans = 1; a %= m; while (b) { if (b & 1)
ans = (a * ans) % m; a = (a * a) % m; b >>= 1; } return ans; }
inline ll divM(ll a, ll b, ll m) { return mulM(a, powM(b, m-2, m), m); }
inline void yes(bool ok, bool capital=true) { if (capital) { if (ok) cout << "YES\n"; 
else cout << "NO\n"; } else{ if (ok) cout << "Yes\n"; else cout << "No\n"; } }
 
//Miller-Rabin 
bool _isPrime(ll n){ if(n<2) return false; for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37}) {
if(n==x) return true; bool flag=true; ll r=1, d=1;
while(r<=((n-1)>>__builtin_ctzll(n-1))) { if(r&((n-1)>>__builtin_ctzll(n-1))) d=((__int128)d*x)%n;
x=((__int128)x*x)%n; r<<=1; } if(d==1||d==n-1) flag=false;
for(r=0;r<__builtin_ctzll(n-1);r++) { d=((__int128)d*d)%n; if(d==n-1) flag=false; }
if(flag) return false; } return true; }
 
//Sieve of Eratosthenes
const int MXP = 1000'005;
// vector<int> prime;
void getPrime()
{
    // prime.resize(MXP);
    // for (int i = 0; i < MXP; i++)
    //     prime[i] = i;
 
    bitset<MXP> isprime(0);
    isprime[0] = isprime[1] = 1;
    for (int i = 2; i * i <= MXP; i++)
    {
        if (isprime[i] == 0)
        {
            for (int j = i * i; j <= MXP; j += i)
            {
                isprime[j] = 1;
                
                // if(prime[j]==j)
                //     prime[j]=i;
            }
        }
    }
 
    // prime.push_back(2);
    // for(int i=3; i<MXP; i+=2)
    //     if(!isprime[i])
    //         prime.pb(i);
}
//-----------------------------------------------------------------------------------------------
//------------------------------------Template---------------------------------------------------
//Vector input
template <typename T> istream &operator>>(istream &in, vector<T> &vec) 
{for (auto &v : vec) in>>v; return in;}
//Vector output
template <typename T> ostream& operator<<(ostream &out, vector<T> &vec) 
{for (auto &v : vec) out<<v<<" "; return out;}
//Pair input
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a)
{in>>a.first>>a.second;return in;}
//Pair output
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a)
{out<<a.first<<" "<<a.second;return out;}
//Find in vector O(logN)
template <typename T1, typename T2> bool vfind(vector<T1> &v, T2 val)
{ return binary_search(v.begin(), v.end(), val); }
 
template<class T> void read(T& x) { cin >> x; }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }
template<class T> void write(T& x) { cout << x <<" "; }
template<class H, class... T> void write(H& h, T&... t) { write(h); write(t...); }
template<class T> inline T ceil(T a, T b){return (a + b - 1)/b;}
//Priority_Queue
template<typename T> using mnHeap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using mxHeap = priority_queue<T>;
//Unordered set and map
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;
//multi set and map
template<typename T> using mset = multiset<T>;
template<typename T1, typename T2> using mmap = multimap<T1, T2>;
//Debugging
void dprint(int64_t t) {cerr << t;}
void dprint(int32_t t) {cerr << t;}
void dprint(string t) {cerr << t;}
void dprint(char t) {cerr << t;}
void dprint(long double t) {cerr << t;}
void dprint(double t) {cerr << t;}
void dprint(unsigned long long t) {cerr << t;}
template <class T1, class T2> void dprint(pair <T1, T2> p);
template <class T> void dprint(vector <T> v);
template <size_t T> void dprint(const bitset<T> &t) { cerr << t; }
template <class T> void dprint(set <T> v);
template <class T> void dprint(multiset <T> v);
template <class T1, class T2> void dprint(map <T1, T2> v);
template <class T1, class T2> void dprint(multimap <T1, T2> v);
template <class T1, class T2> void dprint(pair <T1, T2> a) 
{cerr << "{"; dprint(a.first); cerr << ", "; dprint(a.second); cerr << "}";}
template <class T> void dprint(vector <T> v) {cerr << "[ "; for (T i : v) 
{dprint(i); cerr << " ";} cerr << "]";}
template <class T> void dprint(set <T> v) 
{cerr << "[ "; for (T i : v) {dprint(i); cerr << " ";} cerr << "]";}
template <class T> void dprint(multiset <T> v) 
{cerr << "[ "; for (T i : v) {dprint(i); cerr << " ";} cerr << "]";}
template <class T1, class T2> void dprint(map <T1, T2> v) 
{cerr << "[ "; for (auto i : v) {dprint(i); cerr << " ";} cerr << "]";}
template <class T1, class T2> void dprint(multimap <T1, T2> v) 
{cerr << "[ "; for (auto i : v) {dprint(i); cerr << " ";} cerr << "]";}
// template <class T> void dprint(oset<T> &v)
// {cerr<<"[ ";for(T i: v){dprint(i);cerr<<" ";}cerr << "]";}
//------------------------------------------------------------------------------------------------
void solve()
{
    int n; cin>>n;
    vt<vi> edge(n+1);
 
    For(i, 1, n)
    {
        int x, y; cin>>x>>y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
 
    vi depth(n+1);
    vi dp(n+1);
 
    auto calc=[&](int node, int par, auto calc)->int{
 
        int mx=0;
        bool isleaf=1;
        for(int ii:edge[node])
        {
            if(ii!=par)
            {
                isleaf=0;
                mx=max(mx, calc(ii, node, calc));
            }
        }
        if(!isleaf)
            return depth[node]=mx+1;
        return 0;
    };
    calc(1, 0, calc);
 
    auto helper=[&](int node, int par, auto helper)->void{
        int mx=0;
        int n1=-1, n2=-1;
        for(int ii:edge[node])
        {
            if(ii!=par)
            {
                helper(ii, node, helper);
                mx=max(mx, dp[ii]);
                int tt=depth[ii];
                if(tt>n2)
                {
                    n1=n2;
                    n2=tt;
                }
                else if(tt>n1)
                {
                    n1=tt;
                }
            }
        }
        dp[node]=depth[node];
 
        //Handle
        if(n1!=-1 && n2!=-1)
            dp[node]=max(2+n1+n2, dp[node]);
        
        dp[node]=max(dp[node], mx);
    };
 
 
    helper(1, 0, helper);
    cout<<dp[1]<<el;
}
 
int32_t main() 
{
    FAST;
    IO();
    // IncStackSize();
    auto start=high_resolution_clock::now();
    // cout<<fixed<<setprecision(20);
 
    /***************-Multiple test case-***************/
    int T=1;
    // cin>>T;
 
    for(int ii=1; ii<=T; ii++)
    {
        // cout<<"Case #"<<ii<<": ";
        solve();
    }
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(stop - start);
 
    _Time(duration.count());
    return 0; 
}
