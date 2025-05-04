#include<bits/stdc++.h>
 
// Pbds Datastructure : Get kth element in O(logk)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define nl "\n"
#define ll long long
#define int long long
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define vl vector<ll>
#define vi vector<int>
 
// Using pbds as multiset
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MAX_N = 1e5+5;
const int NINF = -1e9;
const int INF = 1e18;
const int N2 = 1e3;
const int N1 = 1e6+1;
const int N = 1e6;
vector<ll> lowest_p(MAX_N+1,0);
 
 
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll expoS(ll a,ll b){ ll ans = 1; while(b>0){if(b&1)     ans*=a;a = a*a;b >>= 1;}return ans;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;} //nloglogn
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
 
void getLpf(){ ll n = MAX_N; vector<ll> arr(n+1,1);  arr[0] = arr[1] = 0;for(int i=2;i<=n;i++){if(arr[i]==1){lowest_p[i]  = i;for(int j=i*2;j<=n;j+=i){arr[j] = 0;if(lowest_p[j]==0) lowest_p[j] = i;}}}}
 
ll getSetB(ll a)    {return __builtin_popcount(a);}
bool get_bit(ll a,ll i){return a&(1ll<<i);}
 
//-------------------------------------------------------------------------------
void query(int l,int r){
    cout << "? " << l << " " << r << endl;
}
struct Interactor{
    vector<int> arr;
    int hiddenNumber;
    int n;
    int curr_q;
    int limit;
public:
    Interactor(){
        curr_q = 0;
        limit = 15;
        n = getRandomNumber(2,10);
        // n = 5;
        hiddenNumber=2;
    }
    int getN(){
        return n;
    }
    void checkTotalQueries(){
        if(curr_q >= limit){
            cout << "Limit is crossed!! for " <<  hiddenNumber <<   endl;
        }
        assert(curr_q < limit);
    }
    int make_query(int l,int r){
        checkTotalQueries();
        curr_q++;
        
    }
    void isValidOutput(int k){
        
    }
};
//--------------------------------------------------------------------------------
 
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int i = 1;
    // cout << pref[5] - pref[3] << endl;
    while(i<=n){
        ll q = n/i;
        ll temp = n/q + 1;
        ll temp2 = mod_div(mod_mul(temp-1,temp,MOD),2,MOD);
        ll temp3 = mod_div(mod_mul(i-1,i,MOD),2,MOD);
        ll temp4 = mod_sub(temp2,temp3,MOD);
        ll temp5 = mod_mul(q,temp4,MOD);
        // cout << i << " " << temp5 << endl;
        ans = mod_add(temp5,ans,MOD);
        i = temp;
    }
    cout << ans << endl;
}
int32_t main(){
    int t=1;
    // cin >> t;
    // cout << setprecision(10) << fixed;  //Set Precision
    while(t--){
        solve();
    }
 
}
