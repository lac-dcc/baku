#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multiordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
void google(int t) {cout << "Case #" << t << ": ";}
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define ff first
#define ss second    
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define LCM(a,b) (a/__gcd(a,b))*b
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define sz(x) (ll)x.size()
#define ld long double
#define pcnt(x) __builtin_popcountll(x)
const long long I1=1e9;
const long long I2=1e18;
const int32_t M1=1e9+7;
const int32_t M2=998244353;
ll binpow(ll a, ll b)
{
  ll res=1;
  while(b>0)
  {
    if(b%2==1) res=res*a;
    a=a*a;
    b=b/2;
  }
  return res;
}
ll binexp(ll a, ll b, ll mod)
{
  ll res=1;
  while(b>0)
  {
    if(b%2==1) res=((res%mod)*(a%mod))%mod;
    a=((a%mod)*(a%mod))%mod;
    b=b/2;
  }
  return res;
}
ll fact(ll n,ll mod)
{
    ll ans=1;
    for(ll i=2;i<=n;i++)
      ans=((ans%mod)*(i%mod)+mod)%mod;
    ans%=mod;
    return ans;
}
ll nCr(ll n,ll r,ll mod)
{
    ll ri=binexp(fact(r,mod),mod-2,mod);
    ll nri=binexp(fact(n-r,mod),mod-2,mod);
    ll ans=(((fact(n,mod)%mod)*(ri%mod))%mod);
    ans=(((ans%mod)*(nri%mod))%mod);
    ans%=mod;
    ans=(ans+mod)%mod;
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    ll x[n];
    for(ll i=0;i<n;i++) cin>>x[i];
    ll sum=0,ma=-1e9;
    for(ll i=0;i<n;i++)
    {
      ma=max(ma,x[i]);
      if(sum<0) sum=0;
      sum+=x[i];
      ma=max(ma,sum);
    }
    cout<<ma<<endl;
}
int main()
{
  IOS;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
  ll t;
  t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }
}