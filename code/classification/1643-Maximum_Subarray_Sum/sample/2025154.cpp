#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll mx = a[0], sm = a[0];
    for(ll i=1;i<n;i++)
    {
        sm = max(sm+a[i], a[i]);
        mx = max(mx,sm);
    }
    cout<<mx;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}