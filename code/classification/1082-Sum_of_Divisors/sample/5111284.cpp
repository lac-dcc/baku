#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+1;
const long long mod=1e9+7;
const long long mod1=5e8+4;
long long f[N];
long long power(long long a, long long n)
{
    if (n==0) return 1;
    if (n==1) return a;
    else
    {
        if (n%2) return power(a, n-1)*a;
        else
        {
            long long res=power(a, n/2);
            return res*res;
        }
    }
}
long long product(long long l, long long r)
{
    return ((((l+r)%mod)*((r-l+1)%mod))%mod)*mod1%mod;
}
int main()
{
    long long sum=0;
    long long n;
    cin>>n;
    long long t=1;
    long long cost=0;
    while (t<=n)
    {
        long long sl=n/t;
        long long e=n/sl;
        cost=(cost+sl*product(t, e))%mod;
        t=e+1;
    }
    cout<<cost;
}
