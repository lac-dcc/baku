#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MAX=1e6+1;
ll ans[MAX],a[MAX];
int main()
{
    ll n,k;
    cin>>n>>k;
    for (ll i=1; i<=k; i++)
        ans[i] = 1e18;
    for (ll i=0; i<n; i++)
        cin>>a[i],
        ans[a[i]] = 1;
    for (ll i=1; i<=k; i++)
    {
        for (ll j=0; j<n; j++)
        {
            ll x = a[j];
            ll y = i-a[j];
            if (y<0)
                continue;
            ans[i] = min(ans[i],ans[x]+ans[y]);
        }
    }
    cout<<(ans[k]==1e18 ? -1:ans[k]);
    return 0;
}