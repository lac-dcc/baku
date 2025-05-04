#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ld long double
#define vl vector<ll>
#define pl pair<ll, ll>
#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define fl(i, a, b) for (ll i = a; i <= b; i++)
#define bfl(i, k, n) for (ll i = k; i > n; i--)
#define prDouble(d) cout << fixed << setprecision(10) << d
#define deb(x) cerr << #x << " = " << x << "   "
#define endl "\n"
#define int long long
#define inf 1e18
 
const int mod = 1000000007;
const int mod1 = 998244353;
double epsilon = 1e-6;
 
/*-----------------------------------------------------------------------------------------*/
void init_code()
{
#ifndef ONLINE_JUDGE
   freopen("input1.txt", "r", stdin);
   freopen("output1.txt", "w", stdout);
#endif // ONLINE_JUDGE;
}
 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef tree<pair<ll, ll>, null_type, less_equal<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbdsm; // find_by_order, order_of_key
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > pbdss; // find_by_order, order_of_key
  
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbdsm v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbdss v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*-----------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll expo(ll a, ll b, ll mod=1e9+7) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll modinvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll madd(ll a, ll b, ll m=1e9+7) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mmul(ll a, ll b, ll m=1e9+7) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll msub(ll a, ll b, ll m=1e9+7) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mdiv(ll a, ll b, ll m=1e9+7) {a = a % m; b = b % m; return (mmul(a, modinvprime(b, m), m) + m) % m;}  //only for prime m
bool revsort(ll a, ll b) {return a > b;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll modinv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return madd(arr[0], 0, b);} //for non prime b
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
//int fact[2000005]; ll nCr(ll n, ll r, ll mod=1e9+7){if(r>n) return 0; ll res=fact[n]; res=(res*expo(fact[r],mod-2,mod))%mod; res=(res*expo(fact[n-r],mod-2,mod))%mod; return res;}
/*-----------------------------------------------------------------------------------------*/
 
 
int bsearch1(int arr[], int l,int r,int p){
   int ans = -1;
   while(l<=r){
      int mid = (l+r)/2;
      if(arr[mid]>=p) {r = mid-1; ans = mid;}
      else if(arr[mid]<p) {l = mid+1;}
   }
 
   return ans;
}
 
 
void dfs(int ver, int par, int l, vector<set<int>> &gr){
 
   
   for(auto child  : gr[ver]){
      if(child==par) continue;
      dfs(child, ver, l+1, gr);
   }
   
   return;
}
 
 
 
 
void solve()
{  
    int n, w; cin>>n>>w;
    vi arr(n); for(int i=0;i<n;i++) cin>>arr[i];
    vi val(n); for(int i=0;i<n;i++) cin>>val[i];
 
    vector<int> dp(w+1, 0);
    for(int i=arr[0];i<=w;i++){
        dp[i] = val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=w;j>=0;j--){
            if(j>=arr[i]) dp[j] = max(dp[j], val[i] + dp[j-arr[i]]);
            else dp[j] = dp[j];
        }
    }
 
    cout<<dp[w]<<endl;
 
 
 
    
 
 
 
    return;
}
 
 
 
signed main()
{
 
   init_code();
   fastio();
   auto start_time = std::chrono::high_resolution_clock::now();
 
   int T=1;
   //cin>>T;
 
   
   // fact[0] = 1;
   // for(int i=1;i<2000005;i++){
   //    fact[i] = (fact[i-1]*i)%mod;
   // }
 
  
 
 
   
 
   while (T--)
   {
    solve();
   }
 
   
 
   auto stop_time = std::chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
 
#ifndef ONLINE_JUDGE
   cerr << "Time: " << duration.count() / 1000. << " ms" << endl;
#endif
 
    return 0;
}
