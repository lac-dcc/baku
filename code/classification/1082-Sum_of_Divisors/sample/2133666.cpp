#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned long long
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ld long double
#define pb push_back
#define FOR(i,n) for(ll i=0;i<n;i++)
#define FORr(i,n) for(ll i=n-1;i>=0;i--)
#define F first
#define S second
#define MAX 9000000000000000000
#define MIN -9000000000000000000
//vector<vector<int>>a(n,vector<int>(m,0));
//vector<pair<ll,pair<ll,ll>>>a;
/*
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
*/
/*
const ll MOD=1e9+7;
ll sum(ll x){
    return (x*(x+1)/2)%MOD;
}
int main(){
    fast();
    ll n;
    cin>>n;
    ll res=0;
    ll i=1;
    while(true){
        ll a=n/(i+1),b=n/i;
        ll sum1=((sum(b)-sum(a)%MOD)*(i%MOD))%MOD;
        res+=sum1;
        res%=MOD;
        if(i==n){
            break;
        }
        i=n/(n/(i+1));
    }
    cout<<res<<"\n";
    return 0;
}
*/
/*
ll mod = 1000000007;
 
// Functions returns sum
// of numbers from 1 to n
ll linearSum(ll n)
{
    return (n * (n + 1) / 2) % mod;
}
 
// Functions returns sum
// of numbers from a+1 to b
ll rangeSum(ll b, ll a)
{
    return (linearSum(b) -
            linearSum(a)) % mod;
}
 
// Function returns total
// sum of divisors
ll totalSum(ll n)
{
 
    // Stores total sum
    ll result = 0;
    ll i = 1;
 
    // Finding numbers and
    //its occurence
    while(true)
    {
 
        // Sum of product of each
        // number and its occurence
        result += rangeSum(n / i, n / (i + 1)) *
                          (i % mod) % mod;
 
        result %= mod;
 
        if (i == n)
            break;
 
        i = n / (n / (i + 1));
    }
    return result;
}
 
// Driver code
int main()
{
    ll n;
    cin>>n;
    cout<<totalSum(n)<<"\n";
}
 
// This code is contributed by rutvik_56
*/
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
    cin>>n;
    cout<<divisorSum(n)<<"\n";
}
