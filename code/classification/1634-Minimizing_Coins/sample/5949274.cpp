#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve()
{
    ll n,x;
    cin >> n >> x;
 
    vector<ll> v(1e6+10,1e7);
    vector<ll> c(n);
    v[0]=0;
    for(ll i=0; i<n; i++)
    {
        cin >> c[i];
        v[c[i]]=1;
    }
    sort(c.begin(),c.end());
    
    for(ll i=1; i<=x; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(i-c[j]>=0)
            v[i]=min(v[i],1+v[i-c[j]]);
            else
            break;
            // cout << i << " " << v[i] <<"\n";
        }
        
    }
 
    if(v[x]>=1e7)
    cout << -1 << "\n";
    else
    cout << v[x] << "\n";
    
}
 
int main()
{
    ll t=1;
    // cin >> t;
 
    while(t--)
    {
        solve();
    }
 
    return  0;
}