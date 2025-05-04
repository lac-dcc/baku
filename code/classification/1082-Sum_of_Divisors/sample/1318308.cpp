#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("fma")
using namespace std;
const int MOD=1e9+7;
long long suma(long long b,long long a)
{
    return (1LL*b%MOD*((b+1)%MOD)%MOD*((MOD+1)/2)%MOD-1LL*a%MOD*((a+1)%MOD)%MOD*((MOD+1)/2)%MOD+MOD)%MOD;
}
int main()
{
#ifdef HOME
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif // HOME
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    long long n,val=1,s=0;
    cin>>n;
    while(1)
    {
        s=(s+1LL*suma(n/val,n/(val+1))*(val%MOD))%MOD;
        if(val==n)
            break;
        val=n/(n/(val+1));
    }
    cout<<s;
    return 0;
}
