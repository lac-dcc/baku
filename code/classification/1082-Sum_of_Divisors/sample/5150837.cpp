#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 1e9+7;
const ll N=1e6+500 ;
ll Sum(ll n)
{
    return ((n*(n+1))/2)%mod;
}
 
int main()
{
 
    ll tc=1 ;
    //cin>>tc;
 
    while(tc--)
    {
        ll n ; cin>>n;
        ll ans=0;
        for(ll i=1 ; i*i<=n ; i++) ans=(ans+((n/i) * i ))%mod;
        ll left = sqrt(n);
        for(ll i=left ; i>=1 ; i--)
        {
            ll right = n/i;
            ll sum_right = Sum(right%mod)%mod;
            ll sum_left  = Sum(left%mod)%mod;
            ll eq = (sum_right-sum_left+mod)%mod;
            left = right%mod ;
            eq=(eq*i)%mod;
            ans=(ans+eq)%mod;
        }
 
 
        cout<<ans<<endl;
 
    }
 
    return 0;
}