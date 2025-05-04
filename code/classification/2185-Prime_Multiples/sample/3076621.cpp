#include<iostream>
#include<cstdio>
#include<cstring>
#define N 21
#define ll long long
using namespace std;
ll a[N];
int main()
{
    int k;
    ll n;scanf("%lld%d",&n,&k);
    for(int i=0;i<k;i++) scanf("%lld",&a[i]);
    ll ans=0;
    for(int s=1;s<1<<k;s++)
    {
        ll v=n;
        for(int i=0;i<k;i++) if(s>>i&1) v/=a[i];
        if(__builtin_popcount(s)&1) ans+=v;
        else ans-=v;
    }
    printf("%lld\n",ans);
    return 0;
}