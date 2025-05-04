#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update> ;
#define endl '\n'
#define ll long long
#define int long long
#define ld long double
const int32_t INFint = 1e9;
const ll INFll = 1e18;
const ll INF = 9e18;
const ld PI = acos(-1);
 
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define yes cout<<"yes"<<endl; return;
#define no cout<<"no"<<endl; return;
#define vpii vector<pair<int,int>> 
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vector<ll>>
int powersOfTwo[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
int power(int x, int y)
{
    int r = 1;
    while (y > 0)
    {
        if (y & 1)
            r = r * x;
        y = y >> 1;
        x = x * x;
    }
    return r;
}
 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
#define input(arr)                       \
    for (int i = 0; i < arr.size(); i++) \
        cin >> arr[i];
#define show(a)                            \
    {                                      \
        int n = a.size();                  \
        for (int i = 0; i < a.size(); i++) \
        {                                  \
            cout << a[i] << " ";           \
        }                                  \
        cout << endl;                      \
    }
#define nl cout << endl
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
const int MOD = 1e9 + 7;
 
// power function
int binpow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
// euclidean gcd
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
 
// least common multiple
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
 
// factorial of n
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}
 
// sieve
set<int> sieve(int n)
{
    // int n;
    vector<bool> is_prime(n + 1, true);
    set<int> prime;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.insert(i);
        if (is_prime[i] && (long long)i * i <= n)
        {
 
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return prime;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
 
long long C(int n, int r)
{
    if (r > n - r)
        r = n - r; // bebause C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;
 
    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}
 
bool sortby(vi a , vi b){
    return a[1]<b[1];
}
 
int i,j,k,n;
vi fib(50,1);
 
bool check(int mid,vi& a,int t){
    int sum = 0;
    for(auto ele:a) {
        sum+=mid/ele;
        if(mid/ele  == 0 || sum>=t)break;
    }
    return sum>=t;
}
 
void solution(){
   int n,k;
   cin>>n>>k;
   vii arr;
   loop(i,0,n){
    int x;
    cin>>x;
    arr.pb({x,i+1});
   }
   sort(all(arr));
   if(arr.size()<4){
    cout<<"IMPOSSIBLE"<<endl;
    return;
   }
   map<int,pair<int,int>> mp;
   mp[arr[0][0]+arr[1][0]] = {arr[0][1],arr[1][1]};
//    for(auto ele:arr)show(ele);
 
   for(int i=2;i<n;i++){
    for(int j=i+1;j<n;j++){
        int sum = k-arr[i][0]-arr[j][0];
        if(mp.find(sum)!=mp.end()){
            cout<<arr[i][1]<<" "<<arr[j][1]<<" "<<mp[sum].ff<<" "<<mp[sum].ss<<endl;
            return;
        }
    }
    for(int j = i-1;j>=0;j--){
        mp[arr[i][0]+arr[j][0]] = {arr[i][1],arr[j][1]};
    }
   }
   cout<<"IMPOSSIBLE"<<endl;
}
 
int32_t main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int tt = 1;
   //cin >> tt;
    while (tt--)
    {
        solution();
    }
    printclock;
}
