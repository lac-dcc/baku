/* Dhiraj Mehta */
#pragma GCC optimize("O3,unroll-loops")
 
 
#include<bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
 
void oj(){
    #ifndef ONLINE_JUDGE
     freopen("error.txt","w",stderr);
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
}
 
 
// :::::::::::::: MACROS ::::::::::::::::: //
 
#define ll            long long 
#define ff            first
#define ss            second
#define pb            push_back
#define ppb           pop_back
#define all(v)        (v).begin(),(v).end() 
#define mp            make_pair
#define vi            vector<int>
#define vl            vector<ll>
#define pii           pair<int,int>
#define mii           map<int,int>
#define mll           map<ll,ll>
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define rep1(i,a,b)   for(int i=a;i<=b;i++)
#define f(i,n)        for(int i=0;i<n;i++)
#define f2(i,n)       for(int i=0;i<=n;i++)
#define pi            3.141592653589793238462
#define mod           1000000007
#define ppc           __builtin_popcount
#define ppcll         __builtin_popcountll
#define el              "\n"
#define um            unordered_map
#define cy            cout<<"Yes\n";
#define cn            cout<<"No\n";
#define us            unordered_set
#define ub            *upper_bound
#define lb            *lower_bound
#define mae           *max_element
#define mie           *min_element
#define rr            regex_replace
#define pf            push_front
#define ppf           pop_front
#define gcd           __gcd
#define summ(x)       accumulate(all(x), 0LL)
#define fbo(x)        find_by_order(x)
#define ook(x)        order_of_key(x)
#define an(x)         isalnum(x)   /*check if the char. is alphanumeric or not */
 
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 
/* *A.find_by_order(key), A.order_of_key(element),*lower_bound(element),*upper_bound(element)    if use greater instead of 
less we get element in desen order and if use less_equal then 
it works as a multiset. to declare it use 'pbds var. name'*/
 
// find_by_order(K): Returns an iterator to the Kth largest element (counting from zero)
// order_of_key (K): Returns the number of items that are strictly smaller than K
 
 
//::::::::::::::::::: DEBUGGING AREA ::::::::::::::::::: //
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(list <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(list <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(um <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
//:::::::::::::::USEFUL FUNCTIONS::::::::::::::::::://
 
// int count=floor(log10(n))+1;  --> to calculate no. of digits..
 
bool isSquare(int x) {int y = sqrtl(x); return x == y * y;}
bool ispow2(int x) {return (x ? !(x & (x - 1)) : 0);}
int ceils(int x, int y) {return (x >= 0 ? (x + y - 1) / y : x / y);}
int gcd(int x, int y) {return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y) {return x / gcd(x, y) * y;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
const int INF = 1e9+7;
 
/* (lower_bound(v.begin(), v.end(), a[i])-v.begin() ); --> used to find the index of lowerbound element. */
 
bool ispow(int x, long int y)
{
    if (x == 1)
        return (y == 1);
    long int pow = 1;
    while (pow < y)
        pow *= x; 
    return (pow == y);
}
 
int power(int x, int y, int m = INF)
{
    int res = 1;
    x = x % m; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1LL;
        x = (x * x) % m;
    }
    return res;
}
 
bool isprime(int n) 
{   
    if (n < 2)
        return false;
    if (n <= 3) 
        return true; 
    if (!(n % 2) or !(n % 3)) 
        return false; 
    for (int i = 5; i * i <= n; i += 6) 
        if (!(n % i) or !(n % (i + 2))) 
            return false;
    return true; 
}
 
int computeXOR(int n)  //to cal. XOR from 0 to n..
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}
 
 
//:::::::::::::::: ASCII VALUES :::::::::::::::::::: //
    
/* 48-57 -> 0-9
   65-90 -> A-Z
   97-122 -> a-z */
 
 
//:::::::::::::::: CODE START :::::::::::::::::::: //
 
ll ans(int n,ll sum, vl&dp,vl&arr){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(dp[sum]!=-1)return (dp[sum])%INF;
    ll take=0;
    for(int i=0;i<n;i++){
        take+=(ans(n,sum-arr[i],dp,arr))%INF;
    }
    return dp[sum]=(take%INF);
}
 
 
void solve(){
       ll amount,n;
       cin>>n>>amount;
       vl arr(n);
       f(i,n)cin>>arr[i];
       vl dp(amount+1,-1);
       cout<<ans(n,amount,dp,arr)%INF;
       
          
}
 
 
 
 
//:::::::::::::::: CODE ENDS ::::::::::::::::: //
 
 
 
signed main(){
      oj();
       
      ios_base::sync_with_stdio(false);
      cin.tie(0);cout.tie(0);
      
      int t=1;
      // cin>>t;
        while(t--)
            solve();
 
      /* f(i,t){
        cout<<"Case #"<<i+1<<": ";
        solve();
      } */
              
      return 0;
}