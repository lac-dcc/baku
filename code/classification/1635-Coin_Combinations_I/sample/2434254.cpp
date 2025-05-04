#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fr(l,h) for(ll i=l;i<h;i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repo(i,b) for(ll i=0;i<b;i++)
#define repb(i,a,b) for(ll i=b-1;i>=a;i--)
#define repbo(i,b) for(ll i=b-1;i>=0;i--)
#define pr(l,h,arr) for(ll i=l;i<h;i++) {cout<<arr[i]<<" ";} cout<<'\n';
#define endl '\n'
#define MP make_pair
#define csort(a,compare) sort(a.begin(),a.end(),compare())
 
 
 
//--------------------------Containers------------------------/
typedef     long long int           ll;
typedef     unsigned long long int  ull;
typedef     long double             ld;
typedef     vector < int >          vi;
typedef     vector < ll >           vll;
typedef     vector < vll >          vvll;
typedef     pair< int,int >         pi;
typedef     pair< ll, ll >          pll;
typedef     vector< pi >            vpi;
typedef     vector< pll >           vpll;
typedef     vector<string>          vs;
//------------------------------------------------------------/
 
//--------------------------Limits & Constants----------------/
#define     MAX                 200007
#define     MOD                 int(1e9 + 7)
#define     mod                 int(1e9 + 7)
#define     INF                 ll(8230219982008199610)
#define     MINF                ll(-8230219982008199610)
#define     IL                  INT_MAX
#define     MIL                 INT_MIN
#define     PI                  2*acos(0.0)
//------------------------------------------------------------/
 
//--------------------------Macros----------------------------/
#define     mem(a,n)            memset(a, n, sizeof(a) )
#define     gcd(a,b)            __gcd(a,b)
#define     lcm(a,b)            (a*(b/gcd(a,b)))
#define     sz(x)               int(x.size())
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
//------------------------------------------------------------/
 
//------------------------------------------------------------/
ll mul(ll a,ll b){
  return ((a % MOD)*(b % MOD))%MOD;
}
ll add(ll a,ll b){
    return ((a % MOD)+(b % MOD))%MOD;
}
ll sub(ll a,ll b){
    ll ans = ((a%mod) - (b%mod))%mod;
    ans%=mod;
    ans = (ans+mod)%mod;
    return ans;
}
ll mpow(ll a, ll b){
    ll ans = 1;
    ll po = a;
    //b can be written as in binary 2^0 + 2^1+ 2^2+...
    //a^b = a^(2^0 + 2^1+ 2^2+...)
    //a^b = a^(1)*(a^2)*(a^4)*(a^16)...
    while(b!=0){
        if(b%2){
           ans = ((ans%mod)*(po%mod))%mod;
        }
        po = ((po%mod)*(po%mod))%mod;
        b/=2;
    }
    return ans;
}
//------------------------------------------------------------/
 
int n,k,c[101],dp[1000010];
 
// int rec(int level,int sum){
//     if(sum<0){
//         return 1e9;
//     }
//     if(level==-1){
//         if(sum==0){
//             return 0;
//         }else{
//             return 1e9;
//         }
//     }
//     if(dp[level][sum]!=-1)
//         return dp[level][sum];
 
//     int ans=min(rec(level-1,sum),rec(level,sum-c[level])+1);
 
//     dp[level][sum]=ans;
//     return ans;
// }
 
void solve()
{
    cin>>n>>k;
    repo(i,n) cin>>c[i];
    sort(c,c+n);
    dp[0]=1;
    
    for(ll sum=1;sum<=k;sum++){
        dp[sum]=0;
        for(ll i=0;i<n;i++){
            if(sum-c[i]<0) break;
            dp[sum]=add(dp[sum],dp[sum-c[i]]);
        }
    }
    cout<<dp[k]<<endl;
}
 
signed main()
{
    fast;
    ll t;
    //cin>>t; while(t--)
    solve();    
}
