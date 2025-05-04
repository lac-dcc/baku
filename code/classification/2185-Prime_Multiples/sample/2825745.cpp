#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endl "\n"
 
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[k+2];
    for(ll i=0; i<k; i++)cin>>a[i];
    ll m=(1<<k);
    vector<vector<ll>>v;
    for(ll i=0; i<m; i++)
    {
        vector<ll>tem;
        for(ll j=0; j<k; j++)
        {
            if(i&(1<<j))
                tem.pb(a[j]);
        }
        v.pb(tem);
    }
    ll ans=0;
    for(ll i=0; i<v.size(); i++)
    {
        ll div=n;
        if(v[i].size()==0)continue;
        for(ll j=0; j<v[i].size(); j++)
        {
            div=div/v[i][j];
        }
        if(v[i].size()%2==0)
            ans-=div;
        else
            ans+=div;
    }
    cout<<ans<<endl;
    return 0;
}
