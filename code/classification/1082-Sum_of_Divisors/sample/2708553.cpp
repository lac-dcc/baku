// C++ program to calculate sum of divisors
// of numbers from 1 to N in O(sqrt(N)) complexity
#include <iostream>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
/*
Function to calculate x^y using
Modular exponentiation
Refer to https://www.geeksforgeeks.org/
modular-exponentiation-power-in-modular-arithmetic/
*/
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
 
ll divisorSum(ll n)
{
	ll l = 1;
	ll ans = 0;
 
	while (l <= n)
	{
		ll k = n / l;
		ll r = n / k;
		k %= mod;
		
		// For i=l to i=r, floor(n/i) will be k
		ans += ((sum(r) - sum(l - 1) %
						mod) * k) % mod;
		
		// Since values can be very large
		// we need to take mod at every step
		ans %= mod;
		l = r + 1;
	}
	ans = ans % mod;
	// ans can be negative
	// for example n = 831367 ans would be -534577982
	if (ans < 0){
		return ans+mod;
	}else{
		return ans;
	}
}
 
/* Driver program to test above function */
int main()
{                                                                                
  ll n;
  cin >> n;
  cout << divisorSum(n);
}
