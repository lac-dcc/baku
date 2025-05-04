#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    ll n,i,ans=0,p;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;return 0;
    }
    p=sqrt(n);
    for(i=1;i<=p;i++)
    {
        ll d=n/i;
        ans=ans+d*i;
        ans=ans%mod;
    }
    //cout<<ans<<endl;
    ll s,e=n;
    for(i=2;;i++)
    {
        ll x=i-1;
        s=n/i;
        if(s<p)
        {
            s=p;
        }
        ll a,b;
        if(e%2==0)
        {
            a=((e/2)%mod)*((e+1)%mod);
            a=a%mod;
        }
        else
        {
            a=(e%mod)*(((e+1)/2)%mod);
            a=a%mod;
        }
        if(s%2==0)
        {
            b=((s/2)%mod)*((s+1)%mod);
            b=b%mod;
        }
        else
        {
            b=(s%mod)*(((s+1)/2)%mod);
            b=b%mod;
        }
        ll z=a-b;
        if(z<0)z+=mod;
        //cout<<z<<endl;
        //cout<<z<<endl;
        ans=ans+z*x;
        ans=ans%mod;
        e=s;
        if(s==p)
        {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
