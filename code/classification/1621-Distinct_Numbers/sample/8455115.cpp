#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6;
set<ll> se;
int main()
{
    ll n; cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll x; cin>>x;
        se.insert(x);
    }
    cout<<se.size();
}
