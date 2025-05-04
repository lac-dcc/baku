#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod=1e9+7;
 
ll modular_exponent(ll base, ll pow) {
    ll result = 1;
    while (pow > 0) {
        if (pow & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        pow >>= 1;
    }
    return result;
}
 
//ll modular_exponent(ll base,ll pow)
//{
//    if(pow==0)
//    {
//        return 1;
//    }
//    else if(pow%2==1)
//    {
//        ll x=base%mod;
//        ll y=modular_exponent(base,pow-1)%mod;
//        return (x*y)%mod;
//    }
//    else
//    {
//        ll x=modular_exponent(base,pow/2)%mod;
//        return (x*x)%mod;
//
//    }
//}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;cin>>n;
   ll ans=0;
   for(ll i=1,j;i<=n;i=j)
   {
       ll e=n/i;
       j=n/e+1;
       ll range_sum_up_j=(((j%mod)*((j-1)%mod)%mod)*modular_exponent(2,mod-2))%mod;
       ll range_sum_up_i=(((i%mod)*((i-1)%mod)%mod)*modular_exponent(2,mod-2))%mod;
       ll e_sum=(range_sum_up_j%mod-range_sum_up_i%mod+mod)%mod;
       ans=(ans%mod+(e%mod*e_sum%mod)%mod)%mod;
 
 
   }
   cout<<ans<<"\n";
}
 
