#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
 
using namespace std;
 
#define Code ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define rehanmm cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define int ll
#define pb push_back
#define endl '\n'
#define be(v) v.begin(), v.end()
#define eb(v) v.end(), v.begin()
using ll = long long;
using lld = long double;
using ull = unsigned long long;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;
typedef array<int, 2> ar2;
typedef array<int, 3> ar3;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;
#define py cout<< "Yes" <<"\n"
#define po cout<< "1" <<"\n"
#define pm cout<<"-1" << "\n"
#define pn cout<<"No" << "\n"
#define pz cout << 0 << "\n"
#define be(v) v.begin(),v.end()
#define rbe(v) v.rbegin(),v.rend()
#define pyn(ok) ok ? py : pn
#define setbits(X) __builtin_popcountll(X)
#define ff first
#define ss second
#define sz size()
#define mxx(v) *max_element(be(v))
#define mnn(v) *min_element(be(v))
#define msb(x) (31 - __builtin_clz(x))
#define msbll(x) (63 - __builtin_clzll(x))
#define NoSetbitsll(x) __builtin_popcountll(x)
#define setminus(x) memset(x, -1, sizeof(x))
#define setzero(x) memset(x, 0, sizeof(x))
 
// Templates
template<typename T>
istream& operator>>(istream& istream,vector<T>& v) { for (auto& it : v) cin >> it; return istream; }
template <typename T_container,typename T = typename enable_if<!is_same<T_container,string>::value,typename T_container::value_type>::type>
ostream& operator<<(ostream& os,const T_container& v) { string l; for (const T& x : v) os << l << x,l = " "; return os << '\n'; };
 
// Boolean functions
bool sorta(const pll &a,const pll &b){return (a.second < b.second);}
bool sortd(const pll &a,const pll &b){return (a.second > b.second);}
bool paritySame(ll x, ll y) {return !((x & 1) ^ (y & 1));}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
bool isRegularBracketSequence(const string &s) { int balance = 0;for (char c : s) { if (c == '(') {balance++;} else { balance--;}if (balance < 0) {return false;}}return balance == 0;}
 
// Numeric functions
int countDigits(ll n){int k=0;while(n>0){ n = n/10; k++;}return k;}
ll ncr(ll n,ll r){ll ans = 1;for(ll i=n;i>n-r;i--) { ans *= i;} for(ll i=r;i>=1;i--){ans /= i; } return ans;}
ll findMex(vector<ll> &arr){sort(arr.begin(), arr.end()); ll mex = 0; for (ll i = 0; i < static_cast<ll>(arr.sz); i++){ if (arr[i] == mex){ mex++;}} return mex;}
ll sqrt(ll a) { ll l = 0; ll r = a; ll ans = 0; while (l <= r) { ll mid = l + ((r - l) / 2); if (mid * mid <= a) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
ll decimaltobinary(ll n){ll ans = 0;ll x = 0;while (n != 0){ ll bit = (n & 1);ans = (bit * pow(10, x)) + ans;n >>= 1;x++;}return ans;}
ll binarytodecimal(ll n){ll ans = 0;ll x = 0;while (n != 0){ll bit = (n % 10);if (bit % 2 == 1){ans += (1 << x);}n /= 10;x++;}return ans;}
ll countPrimes(ll n){vector<bool> ans(n + 1, 1);ans[0] = ans[1] = 0;ll prime = 0;for (ll i = 2; i < n; ++i){if (ans[i]){prime++;for (ll j = 2 * i; j < n; j += i){ans[j] = 0;}}}return prime;}
vll factorization(int n){vll v; for (int i=1;i*i<=n;i++){if (n%i==0){v.pb(i);if (i*i!=n){v.pb(n/i);}}}return v;}
vll prefixSum(vll &v) { vll pre(v.sz+1); partial_sum(be(v), pre.begin()+1); return pre; }
vll prime_factorization(ll n){vll v; for (int i=2;i*i<=n;i++){while(n%i==0){n/=i;v.pb(i);}}if (n!=1){v.pb(n);}return v;}
 
// Mathematical functions
ll power(int a,ll b){ ll ans = 1; for (int i = 0; i < b;i++){ ans *= a; } return ans; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
ll powm(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }  //power modulo m
void extendgcd(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } //pass an array of size 3
ll mminv(ll a, ll b) { ll arr[3]; extendgcd(a, b, arr); return arr[0]; } //for non prime b
ll mminvprime(ll a, ll b) { if (a % b == 0) return -1; return powm(a, b - 2, b); } //for prime only
vector<ll> sieve(int n) { int* arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (int j = i * i; j <= n; j += i)arr[j] = 1; } return vect; }
vector<string> split(string s, char delimeter) { vector <string> tokens; stringstream check1(s); string intermediate; while (getline(check1, intermediate, delimeter)) { tokens.push_back(intermediate); } return tokens; }
string stringRemZeroes(string s) { string res; bool flag = true; for (int i = 0;i < s.length();i++) { if (s[i] == '0' && flag) continue; else { flag = false; res.push_back(s[i]); } } if (res.size() == 0) res = "0"; return res; }
void toLower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }
void toUpper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
ll stringToNo(string s) { stringstream din(s); ll x; din >> x; return x; }
template<typename R,typename T> R genT(int n,T l, T r) { srand(time(NULL)); R ans; int width = r - l+1; for (int i = 0; i < n;i++){ T number = rand() % width + l; ans.push_back(number); } return ans; }
 
int xorSum(vll &arr, int n) { int bits = 0; for (int i=0; i < n; ++i) { bits |= arr[i]; bits = bits % mod; } int ans = (bits * powm(2, n-1,mod))%mod; return ans; } 
 
// write code such that you can debug each part separately
void soln() {
// cerr << genT<vll,int>(4, 1, 9);
int n, m;
cin >> n >> m;
vector<vll> adj(n + 1);
for (int i = 0; i < m;i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vll parent(n + 1,-1);
parent[1] = -1;
vll dist(n + 1,INF);
dist[1] = 0;
set<pll> st;
st.insert({0, 1});
while(!st.empty()){
    auto it = *st.begin();
    st.erase(it);
    int dis = it.first;
    for (auto node : adj[it.second])
    {
        if (dist[node]>dist[it.second]+1){
            dist[node] = dist[it.second] + 1;
            st.insert({dist[node], node});
            parent[node] = it.second;
        }
   }
}
int i = n;
vector<int> ans;
while(parent[i]!=-1){
    ans.push_back(i);
    i = parent[i];
}
if(ans.empty()){
    cout << "IMPOSSIBLE" << endl;
    return;
}
ans.push_back(1);
cout << ans.size() << endl;
reverse(be(ans));
cout << ans;
}
 
int32_t main() {
    Code By rehanmm
    int t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}
