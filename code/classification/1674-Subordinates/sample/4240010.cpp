#ifndef IdontEvenknowWhatsHappening
#include <bits/stdc++.h>
 
// #define PBDS
 
#ifdef PBDS
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#endif
 
using namespace std;
#ifdef PBDS
using namespace __gnu_pbds;
#endif
 
/***************************Start Of Template********************/
#ifndef Constants
#define MOD (int)1000000007
#define MOD1 (int)998244353
#define INF (int)1e18
#define PI 3.141592653589793238462
#define MAX (int)1e9
#define MIN (int)-1e9
#endif
 
#define int long long
 
#ifndef DataTypeShorthands
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<string> uss;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
typedef map<int,int> mii;
#ifdef PBDS
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order, order_of_key
#endif
#endif
 
#ifndef RegularFunctions
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define set_bits __builtin_popcountll // count set bits in integer
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define br printf("\n")
#endif
 
#ifndef InputShorts
#define gtarr(arr,beg,end) for(int i = beg; i < end; i++) cin>>arr[i];
#define gta(arr,end) for(int i = 0; i < end; i++) cin>>arr[i];
#define ptarr(arr,beg,end) for(int i = beg; i < end; i++) cout<<arr[i]<<" ";
#define pta(arr,end) for(int i = 0; i < end; i++) cout<<arr[i]<<" ";
#define gtv(arr,end) for(int i=0;i<end;i++) {int temp;cin>>temp;arr.push_back(temp);}
#endif
 
#ifndef Debugging
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define deb(x,n) cerr << #x <<" "; _print(x,n); cerr << endl;
#else
#define debug(x)
#define deb(x,n)
#endif
 
template<class T>void _print(T t) {cerr << t;}
 
template <class T> void _print(T v[], int n);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(T v[], int n){cerr << "[ ";for (int i = 0; i < n; i++){_print(v[i]);cerr << " ";}cerr << "]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#ifdef PBDS
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#endif
 
#endif
 
#ifndef NumberTheory
template <typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
template <typename T> T exp(T a, T b, T mod) {T res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
template <typename T> void extendgcd(T a, T b, T*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); T x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
template <typename T> T minv(T a, T b) {T arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
template <typename T> T minvprime(T a, T b) {return exp(a, b - 2, b);}
template <typename T> T mod_add(T a, T b, T m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
template <typename T> T mod_sub(T a, T b, T m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
template <typename T> T mod_mul(T a, T b, T m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
template <typename T> T mod_div(T a, T b, T m) {a = a % m; b = b % m; return (mod_mul(a, minvprime(b, m), m) + m) % m;}  //only for prime m
template <typename T> T combination(T n, T r, T m, T *fact, T *ifact) {T val1 = fact[n]; T val2 = ifact[n - r]; T val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template <typename T> T permutation(T n, T r, T m, T *fact, T *ifact) {T val1 = fact[n]; T val2 = ifact[n - r]; return ((val1 * val2) % m);}
template <typename T> T phin(T n) {T number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (T i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N)) /*Don't know this one yet*/
void sieve(bool* sieve, int n) {/*memset(sieve,true,sizeof(sieve));*/ for(int i=0; i<n; i++) sieve[i] = true; for(int i=2; i*i<n; i++) if(sieve[i] == true) for(int j=i*i; j<n; j+=i) sieve[j] = false;}
void spfsieve(int* sieve,  int n) {for(int i=1; i<n; i++) sieve[i] = i; for(int i=2; i*i<n; i++) if(sieve[i] == i) for(int j=i*i; j<n; j+=i) if(sieve[j] == j) sieve[j] = i;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = (i * i); j <= n; j += i)arr[j] = 1;} return vect;}
#endif
/*************************End Of Template*************************/
 
#endif
 
void dfs(vector<vector<int>>& edge, vector<int>& ans, int root, int parent) {
    ans[root]++;
    for(int i=0; i<edge[root].size(); i++) {
        if(edge[root][i] == parent) {
            continue;
        }
        dfs(edge,ans,edge[root][i],root);
        ans[root] += ans[edge[root][i]];
    }
}
 
void solve() {
    int n;
    cin >> n;
    vi parent(n+1,-1), ans(n+1,0);
    vector<vector<int>> edge(n+1);
    for(int i=1; i<n; i++) {
        cin >> parent[i+1];
        edge[i+1].push_back(parent[i+1]);
        edge[parent[i+1]].push_back(i+1);
    }
    debug(parent);
    debug(edge);
    dfs(edge,ans,1,-1);
    for(int i=0; i<n; i++) {
        cout << ans[i+1]-1 << " ";
    }
    cout << endl;
}
 
int32_t main() {
    
    #ifndef ONLINE_JUDGE
        freopen("../error.txt", "w", stderr);
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
 
    fastio();
    int t=1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
