#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
 
ll sumi(ll n)
{
    ll a,b;
    if(n&1)
    {
        b=(n+1)/2;
        a=n;
    }
    else
    {
        a=n/2;
        b=(n+1);
    }
    return ((a%mod)*(b%mod))%mod;
}
int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
  ll n;
    cin>>n;
    
    ll sum=0;
   for(ll i=1;i*i<=n;i++)
   {
 
   ll count=(n/i)-i+1;
    
    sum+=(count%mod)*i;
    sum%=mod;
    sum+=sumi(n/i)-sumi(i);
    sum+=mod;
    sum%=mod;
      }
   cout<<sum<<"\n";
}
