/**
 *    author:  nibbleCoder
 *    created: 12.11.2021 20:05:00
**/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
// **********************#define********************************
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define fbo(a) find_by_order(a) //will give a-th largest element or a-th element in the pb_ds container
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a or index of the key
#define bitcount(x)   __builtin_popcountll(x)  //will give the number of 1-bits set in x
#define firstSetBitL(x) __builtin_ctz(x) //will give count trailing zeros or first set bit from left
#define str string
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define rfo(i,a,n) for(ll i=n-1;i>=a;i--)
#define eb emplace_back // emplace_back more faster than push_back because emplace_back would construct the object immediately in the vector, while push_back , would first construct an anonymous object and then would copy it to the vector. 
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define sp(x,y) fixed<<setprecision(y)<<x
#define nl '\n'
#define MOD 1000000007
#define _p(str) cout << str << nl
#define _ap(i,a,n,A) for(ll i=a;i<n;i++) cout << A[i] <<" ";
#define MAX 1000005
 
// **********************typedef***************************************
 
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<ll> > vv;
typedef vector< bool> vbool;
// Declaring Ordered Set
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
// *********************************for debugging*************************************
 
#define deb(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]) { return N; } template<typename T> int SIZE(const T &t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)),  __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += "\n"; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += "\n"; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += "\n"; return res; } void dbgm() {;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cerr << to_string(H) << " | "; dbgm(T...); }
#define debm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl
 
 
//---------------------------------------------------------------------------------------------
 
void FIO() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
}
 
//*****************************functions******************************************************
void google(ll t) {
 
#ifndef ONLINE_JUDGE
  if ( t != 1 )  cout << nl ; cout << "Case #" << t << ": ";
#endif
}
 
//****************************modular arithmetic**********************************************
 
ll mod_add(ll a, ll b, ll m) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a %= m; b %= m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a %= m; b %= m; return (((a - b) % m) + m) % m;}
 
/*------------------------------bitmasks-----------------------------------------------------*/
ll setbit(int n, int pos  ) { return n = n | (1 << pos) ; }
ll resetbit(int n, int pos ) {  return n =  n & ~(1 << pos ); }
bool checkbit(int  n, int pos ) { return (bool ) (n & (1 << pos))  ; }
ll bin_pow( ll a , ll b, ll mod ) { if ( a == 0 ) return 0; ll res = 1; while ( b > 0 ) { if ( b % 2 ) res = ( res * a ) % mod; b = b / 2;  a = ( a * a ) % mod; }  return res; }
vector< bool >prime( MAX , true );
 
void SieveOfEratosthenes() { prime[ 0 ] = false ;  prime[1] = false; for (ll p = 2; p * p <= MAX; p++) { if (prime[p] == true) { for (ll i = p * p; i <= MAX; i += p) prime[i] = false; } } }
 
//*********************************************************************************************
 
inline ll read() { ll x = 0, f = 1; char ch = getchar();  while (ch > '9' || ch < '0') {if (ch == '-') f = -1; ch = getchar();} while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}  return x * f; }
template<class T> istream& operator >> (istream &is, vector<T>& V) { for (auto &e : V) is >> e; return is; }
/*********************************************************************************************/
 
// I believe in myself and I can 
// I will give my best all by myself
 
// So solve A in first 5 mins
// Solve B in next 10-15 mins
// Solve C in next 30 mins
 
// Try solving D for the rest time
 
// Just go and play with numbers
 
class Operation {
public:
 
  void solve(ll t) {
     
     ll n, x;
 
     cin >> n >> x;
 
     vll C(n);
 
     cin >> C;
 
     vll DP( x+1, INT_MAX );
 
     DP[0] = 0;
 
     fo( i, 0 , x ){
 
         if( DP[i] == INT_MAX ) continue;
 
         fo( j , 0, n ){
 
            if(( i + C[j] )<= x )
                DP[ i + C[j] ] = min( DP[ i + C[j] ] , DP[i] + 1 );
         }
     }
 
     if( DP[x] == INT_MAX )
        _p(-1);
 
     else
       _p(DP[x]);
  }
};
 
int main() {
 
  FIO();
 
  ll t = 1;
//  cin >> t;
 
  Operation solution;
 
  for (ll i = 1 ; i <= t ; i++ )
    solution.solve(i);
}