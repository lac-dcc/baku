
// -------------------------Solution by Aditya Raj------------------------- //
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cctype>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long
 
// for ordered_set : less<node>
// for ordered_multiset : less_equal<node>
 
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
double eps = 1e-12;
ll MOD = 998244353;
ll mod = 1000000007;
#define fr(i, a, b) for(int i = a;i < b;i++)
#define fr_inv(i, a, b) for(int i = a;i >= b;i--)
#define nl "\n"
#define INF 2e18
#define pi  2*acos(0.0)
#define Raftar_ka_Junoon() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
#define square(x) x * x
#define cube(x) x * x * x
#define PYES cout<<"YES"
#define PNO cout<<"NO"
#define PYes cout<<"Yes"
#define PNo cout<<"No"
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
#define debug(x) cerr << (#x) << " is "; _print(x); cerr << nl;
#else
#define debug(x);
#endif
 
// -----------------------------Debugging Statements----------------------------- //
 
void _print(ll t) {cerr << t;}
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
// void _print(ordered_set v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
// -------------------Modular Operations------------------- //
 
int power(long long x, unsigned int y, int p)   // (x ^ y) % p
{
    if(x == 0){
        return 0;
    }
    if(y == 0){
        return 1;
    }
    int val;
    // y -> even
    if(y % 2 == 0){
        val = power(x, y / 2, p);
        val = (val * val) % p;
    }
    // y -> odd
    else{
        val = x % p;
        val = (val * (power(x, y - 1, p) % p)) % p;
    }
    return ((val + p) % p);
}
 
 
unsigned long long modInverse(unsigned long long n,  
int p)
{
return power(n, p - 2, p);
}
 
int add(int x, int y, int m){int val = ((x % m) + (y % m)) % m;return val;}
int subtract(int x, int y, int m){int val = ((x % m) - (y % m) + m) % m;return val;}
int multiply(int x, int y, int m){int val = ((x % m) * (y % m)) % m;return val;}
int divide(int x, int y, int m){x = x % m;y = modInverse(y, m);return (x * y);}
 
// -------------------I/O Template------------------- //
 
template <typename T> ostream& operator <<(ostream& output, const vector<T>& data)
{
      for (const T& x : data)
            output << x <<" ";
      return output;
}
 
 
template <typename T> istream& operator>>(istream& input,vector<T>& data)
{
      for (auto& item : data)
      {
           input >> item;
      }
      return input;
}
 
// -------------------Sieve of Erastothenes------------------- //
 
map<int, int>map_for_prime;
void sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    map_for_prime[2] = 1;
    for(int i = 3;i < n;i += 2)
    {
      map_for_prime[i] = 1;
    }
}
 
// -------------------Prime Factors in sqrt(N)------------------- //
 
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        // 2
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            // i
            n = n/i;
        }
    }
    if (n > 2)
    {
        // n
    }
}
 
// -------------------Number of Divisors------------------- //
 
int NODiv(int n)
{
    int cnt = 0;
    for(int i = 1;i * i <= n;i++)
    {
        if(i * i == n)
        {
            cnt++;
            continue;
        }
        cnt += 2;
    }
    return cnt;
}
 
// -------------------nCr(Binomial)------------------- //
 
int nCr(int n, int k) 
{
    if(n < k)
    {
        return 0;
    }
    if(k == 0)
    {
        return 1;
    }
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,int r, int p)
{
// If n<r, then nCr should return 0
if (n < r)
    return 0;
// Base case
if (r == 0)
    return 1;
 
unsigned long long fac[n + 1];
fac[0] = 1;
for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
   return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 
 
// -------------------Checking Prime (O(root(n))------------------- //
 
bool isPrime(int x) {
  for (int d = 2; d * d <= x; d++) {
      if (x % d == 0)
          return false;
  }
  return true;
}
 
// -------------------Important Notes------------------- //
 
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on
 
// -----------------------Solve------------------------ //
 
const int N = 1e5 + 5;
 
// first -> sum
// second -> prefix max
 
void build(vector<int> &a, int n, vector<pair<int, int>> &segtree){
    for(int i = 0;i < n;i++){
        segtree[i + n].first = a[i];
        segtree[i + n].second = a[i];
    }
    for(int i = n - 1;i >= 0;i--){
        segtree[i].second = segtree[i + i].second + segtree[i + i + 1].second;
        segtree[i].first = max(segtree[i + i].first, segtree[i + i].second + segtree[i + i + 1].first);
    }
}
 
void update(int pos, int n, int x, vector<int> &a, vector<pair<int, int>> &segtree){
    a[pos] = x;
    int l = pos + n;
    segtree[l].first = x;
    segtree[l].second = x;
    l /= 2;
    while(l > 0){
        segtree[l].second = segtree[l + l].second + segtree[l + l + 1].second;
        segtree[l].first = max(segtree[l + l].first, segtree[l + l].second + segtree[l + l + 1].first);
        l /= 2;
    }
}
 
int query(int l, int r, vector<pair<int, int>> &segtree, int n){
    l += n;
    r += n;
    pair<int, int>x = {0, 0};
    pair<int, int>y = {0, 0};
    while(l <= r){
        if(l % 2 == 1){
            x = {max(x.first, x.second + segtree[l].first), x.second + segtree[l++].second};
        }
        if(r % 2 == 0){
            y = {max(segtree[r].first, segtree[r].second + y.first), segtree[r--].second + y.second};
        }
        l /= 2;
        r /= 2;
    }
    return max(x.first, x.second + y.first);
}
 
void lets_solve(){
    int n, m;
    cin>>n>>m;
    vector<int>a(n);
    cin>>a;
    vector<pair<int, int>>segtree(n + n);
    build(a, n, segtree);
    while(m--){
        int c;
        cin>>c;
        if(c == 1){
            int l, r;
            cin>>l>>r;
            update(--l, n, r, a, segtree);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<query(--l, --r, segtree, n)<<endl;
        }
    }
    debug(segtree)
}
signed main()
{
    Raftar_ka_Junoon();
    auto start1 = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int test_cases = 1;
    // cin >> test_cases;
    int test_case_no = 1;
    while(test_cases--) {
    // cout<<"Case #"<<test_case_no<<": ";
    test_case_no++;
        lets_solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << nl;
    #endif
    return 0;
}
