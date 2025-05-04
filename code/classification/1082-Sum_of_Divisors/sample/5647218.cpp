#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
 
using namespace std;
 
const long long int MOD = 1e9+7;
 
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
 
int main()
{
    long long int n;
    cin >> n;
    long long int sum = 0;
    for(long long int i = 1; i <= sqrt(n); ++i){
        long long int t1 = i * (n / i - i + 1);
        sum += t1%MOD;
        long long int t2 = ((((n / i)%MOD) * ((n / i + 1)%MOD)) / 2) - ((i * (i + 1)) / 2);
        while(t2 < 0){
            t2 += MOD;
        }
        sum += t2%MOD;
        sum %= MOD;
    }
    cout << sum%MOD << '\n';
    // cout << "The sum of divisors of all \
    //             numbers from 1 to " << n << " is: " \
    //                         << divisorSum(n) << '\n';
    return 0;
}
