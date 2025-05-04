#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> v1,v2;
ll t[45];
ll n;
void recurse(ll ind,ll sum,ll p)
{
    if(ind==p)
    {
        if(p==n/2)
        {
            v1.push_back(sum);
        }
        else
        {
            v2.push_back(sum);
        }
        return;
    }
    else
    {
        recurse(ind+1,sum+t[ind],p);
        recurse(ind+1,sum,p);
    }
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll x;
    cin>>n>>x;
    for(ll i=0;i<n;i++)
    {
        cin>>t[i];
    }
    recurse(0,0,n/2);
    recurse(n/2,0,n);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll res = 0;
    for(ll i=0;i<v1.size();i++)
    {
        ll ind1 = lower_bound(v2.begin(),v2.end(),x-v1[i])-v2.begin();
        ll ind2 = upper_bound(v2.begin(),v2.end(),x-v1[i])-v2.begin();
        res+= ind2-ind1;
    }
    cout<<res<<"\n";
}
