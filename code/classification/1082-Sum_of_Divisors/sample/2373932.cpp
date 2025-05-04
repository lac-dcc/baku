#include <iostream>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
ll power(ll x, ll y, ll p)
{
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
 
ll modinv(ll x)
{
	return power(x, mod - 2, mod);
}
 
ll sum(ll n)
{
	ll retval = ((((n % mod) * ((n + 1) %
		mod)) % mod) * modinv(2)) % mod;
	return retval;
}
 
ll divisorSum(ll n)
{
	ll l = 1;
	ll ans = 0;
 
	while (l <= n)
	{
		ll k = n / l;
		ll r = n / k;
		k %= mod;
		
		ans += ((sum(r) - sum(l - 1) %
						mod) * k) % mod;
		
		ans %= mod;
		l = r + 1;
	}
	ans = ans % mod;
	if (ans < 0){
		return ans+mod;
	}else{
		return ans;
	}
}
 
 
int main()
{
	ll n;
	cin >> n;
	cout << divisorSum(n) << endl;
	return 0;
}
