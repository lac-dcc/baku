#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define EPS 1e-9
#define dist(x,y) sqrt(abs(x) +abs(y))
#define pno cout<<"NO\n"
#define pys cout<<"YES\n"
int32_t main()
{
ll n,x;
cin>>n>>x;
ll a[n],i,j;
map<ll,stack<ll>> mp;
for(i=0;i<n;i++)
{
    cin>>a[i];
    mp[a[i]].push(i+1);
}
sort(a,a+n);
vector<ll> v;
ll ind=0;
for(i=0;i<n-2;i++)
{
    for(j=i+1;j<n-1;j++)
    {
        ll k=j+1,l=n-1;
        while(k<l)
        {
            if((a[i]+a[j]+a[k]+a[l])==x)
            {
             v.pb(mp[a[i]].top());
            mp[a[i]].pop();
             v.pb(mp[a[j]].top());
            mp[a[j]].pop();
             v.pb(mp[a[k]].top());
            mp[a[k]].pop();
             v.pb(mp[a[l]].top());
            mp[a[l]].pop();
            ind=1;
            break;
            }
            else if((a[i]+a[j]+a[k]+a[l])>x)
            {
                l--;
            }
            else
            {
                k++;
            }
        }
        if(ind==1)
        {
            break;
        }
    }
    if(ind==1)
    {
        break;
    }
 
}
if(v.empty())
{
    cout<<"IMPOSSIBLE";
}
else
{
for(auto x:v)
{
cout<<x<<" ";
}
}
return 0;
}