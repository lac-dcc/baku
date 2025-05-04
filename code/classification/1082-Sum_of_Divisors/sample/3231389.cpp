#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define mod 1000000007
 
ll power(ll x, ll y, ll p)
{
     
    // re x^y if p not specified
    // else (x^y)%p
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}
 
// Function to find modular
// inverse of a under modulo m
// Assumption: m is prime
ll modinv(ll x)
{
    return power(x, mod - 2, mod);
}
 
// Function to calculate sum from 1 to n
ll sum(ll n)
{
    // sum 1 to n = (n*(n+1))/2
    ll retval = ((((n % mod) * ((n + 1) %
        mod)) % mod) * modinv(2)) % mod;
    return retval;
}
ll sumofdivisors(ll n){
    ll ans = 0;
    for(ll i=1;i*i<=n;i++){
        ll t1 = (i*((n/i - i + 1)%mod))%mod;
        ll t2 = (sum(n/i) - sum(i))%mod;
        ans+=((t1+t2)%mod);
    }
    ans %=mod;
    if(ans < 0)
     return ans+mod;
    else 
      return ans;
}
signed main(){
    ll n;
    cin>>n;
    ll ans = sumofdivisors(n);
    cout << ans << "\n";
    return 0;
}
