#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    ll n, k;
    cin >> n >> k;
    ll p[k];
    for(ll i=0;i<k;i++)cin>>p[i];
    ll lm= 1 << k;
    ll ans=0;
    for(ll i=1;i<lm;i++)
    {
        ll cc=0, mul=n;
        for(ll j=0;j<k;j++)
        {
            if(i & ( 1 << j ))
            {
                cc++;
                mul/=p[j];
            }
        }
        if(cc%2)ans+=mul;
        else
        ans-=mul;
    }
    cout << ans ;
}