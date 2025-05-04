#include<bits/stdc++.h>
#define ll  long long int
using namespace std;
 
#define mod 1000000007
 
ll binpow(ll a, ll b, ll m) 
{
    a %= m;
    ll res = 1;
    while (b > 0)
	{
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    
    return (res+m)%m;
}
 
ll modinv(ll x)
{
return binpow(x, mod-2, mod);
}
 
ll sum(ll x)
{	
ll val = (((x%mod)*((x+1)%mod))%mod)*(modinv(2))%mod;	
val = val%mod;
return val;
 
}
 
ll divisor_sum(ll n)
{
ll ans = 0;	
ll i = 1;
	
while(i<=n)
{
ll k = n/i;
ll r = n/k;
k = k%mod;
 
ans = (ans + ((sum(r)-sum(i-1) + mod)%mod)*k)%mod;
ans = ans % mod;
i = r+1;
 
}	
	
return ans % mod;	
}
 
 
 
int main()
{
ll n;
cin>>n;
 
cout<<divisor_sum(n);
 
	
	return 0;
}
