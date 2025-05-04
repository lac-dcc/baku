#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define intarr(arr, n)  ll arr[n];  for (ll i = 0; i < n; i++)  cin >> arr[i]
#define inpvec(v,n) for(ll i=0;i<n;i++){ll var;cin>>var;v.push_back(var);}
#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
#define vec vector<ll>
#define pi pair<ll,ll>
#define changeline cout<<endl
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define NO cout << "NO" <<endl
#define YES cout << "YES" <<endl
#define mem(arr,val) memset(arr,val,sizeof(arr));
const ll mod = 1e9+7;
const ll inf = LLONG_MAX;
#define mod2 998244353
#define piii 3.14159265358979323846264338327950
#define print(a, n, m)     for (ll i = n; i < m; i++) {  cout << a[i] << " "; } cout << endl
#define con continue
 
bool prime(ll n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return 1; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
 
    return 1; 
}
bool isPerfectSquare(ll x1) {   
  long double sr = sqrt(x1); 
  return ((sr - floor(sr)) == 0); 
} 
bool isPowerOfTwo(ll n) {
    return n > 0 && !(n&(n-1));
}
bool subsequence_checker(string str1, string str2, ll m, ll n) 
{ 
    if (m == 0) return 1; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return subsequence_checker(str1, str2, m-1, n-1); 
    return subsequence_checker(str1, str2, m, n-1); 
}
bool cmp(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return (a.ff > b.ff); 
}
ll gcd(ll p, ll q){
if(p % q == 0)return q;
return gcd(q, p % q);
}
ll countDigit(ll n) 
{ 
    return floor(log10(n) + 1); 
}
ll power(ll a,ll n)
{
  if(n==0)
    return 1;
  if(n%2)
    return (a*power((a*a)%mod,n/2))%mod;
  return power((a*a)%mod,n/2);
}
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
ll setBitNumber(ll n) 
{ 
    n |= n >> 1; 
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n = n + 1; 
 
    return (n >> 1); 
} 
ll ncr(ll n , ll row)
{
    if(n<row) return 0;
    if(row==1) return n;   
    if(row==2) return (n*(n-1))/2;
    return (n*(n-1)*(n-2))/6;
} 
ll countDivisors(ll n) { 
    ll count =0 ;
    for (ll i = 1; i*i < n; i++) 
        if (n % i == 0) 
            count++; 
    for (ll i = sqrt(n); i >= 1; i--) 
        if (n % i == 0) 
            count++; 
    return count;
} 
vector<ll> printDivisors(ll n){
    vector<ll> d ;
    for (ll i = 1; i*i < n; i++)
        if (n % i == 0){
            d.push_back(i);
            //cout<<i<<" ";
        }
    for (ll i = sqrt(n); i >= 1; i--)
        if (n % i == 0){
            d.push_back(n/i);
            //cout<<n/i<<" ";
        }
    return d;
}
///////////////////////////////////Lets Do It///////////////////////////////////
void calcsubarray(vec &a, vec &x, ll n, ll c)
{
    for (ll i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        // x[i] = s;
        x.pb(s);
    }
}
 
 
void solve()
{   
 
    ll n,s;
    cin>>n>>s;
    vec a;
    inpvec(a,n);
 
    vector<ll> x;
    vector<ll> y;
 
    calcsubarray(a,x,n/2,0);
    calcsubarray(a,y,n-n/2,n/2);
 
    sort(all(y));
    // print(x,0,x.size());
    // print(y,0,y.size());
 
    ll ans = 0;
    loop(i,0,x.size())
    {
        if(x[i]==s){
            ans++;
        }
        else if(x[i]<s)
        {
            ll up = upper_bound(all(y),s-x[i])-y.begin();
            ll p = lower_bound(all(y),s-x[i])-y.begin();
            // if(p==y.size()) 
            //     p--;
 
            if(p!=y.size() && y[p]== s-x[i])
                ans+=(up-p);
        }
    }
    cout<<ans;
}   
 
int main()
{   
 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "row", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
 
    ll t;
    // cin>>t;
    t=1;    
 
    while(t--){
        solve();
        cout<<endl;
    }
 
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
 
    return 0;
} 
