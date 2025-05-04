#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double lld;
typedef vector<int> vi;
typedef vector<lld> vd;
typedef vector<ll> vl;
 
#define pi(x) printf("%d", x);
 
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>>  vvvl;          
#define PI 3.141592653589793238462
const ll MOD = 1000000007;
#define pb push_back     
#define f first     
#define s second
#define mp make_pair         
#define nl "\n"
#define sp " "
#define fi(i,a,n) for(ll i=a;i<n;i++) //increasing for loop
#define fd(i,a,n) for(ll i=a;i>n;i--) // decreasing for loop
#define trav(a,x) for (auto& a : x) // for traversing into the whole
//---------------degugging------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nl;
#else
#define debug(x);  
#endif     
template<class T,class V> void _print(pair<T,V> p);
template<class T>void _print(set<T> v);
template<class T>void _print(multiset<T> v) ;
template<class T,class V>void _print(map<T, V> v);
template<class T>void _print(vector<T> v);
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
//---------------------------------------imp functions--------------------------------------------------
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod=MOD) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
 
//-------------------------------------------------------------------------------------------------------
void solve(){
    ll V,E;
    cin>>V>>E;
    ll inf = 1e18;
    
    vector<vector<ll>> Edges;
    vector<ll> par(V+1,-1);
    vector<ll> dist(V+1,inf);
    dist[1] = 0;
    ll x,y,z;
    for(ll i = 0; i < E ; i++){
        cin >> x >> y >> z;
        Edges.pb({z,x,y});
    }
    // sort(Edges.begin(),Edges.end());
 
    for(int i = 0; i < V ; i++){
        for(auto g : Edges){
            if(dist[g[2]] > dist[g[1]] + g[0]){
                dist[g[2]] = dist[g[1]] + g[0];
                par[g[2]] = g[1];
            }
        }
        debug(dist);
    }
 
    ll c = -1;
    for(auto g : Edges){
        if(dist[g[2]] > dist[g[1]] + g[0]){
                dist[g[2]] = dist[g[1]] + g[0];
                c = g[1];
                par[g[2]] = g[1];
        }
    }
    debug(dist);
    if(c == -1) {
        cout << "NO" << '\n'; return;
    }
 
    for(int i = 1 ; i <= V ; i++){
        c = par[c];
    }
 
    vector<ll> ans;
 
    for(int x = c ; ; x = par[x]){
        ans.pb(x);
        if(c==x and ans.size() > 1) break;
    }
 
    if(ans.size() > 1){
        cout << "YES" << '\n';
        reverse(ans.begin(),ans.end());
        for(int i = 0; i <ans.size() ; i++) cout << ans[i] << " ";
    }
 
    
     
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precision(9);
    int T=1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
