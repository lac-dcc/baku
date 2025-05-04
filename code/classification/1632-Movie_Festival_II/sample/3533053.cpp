#include<bits/stdc++.h>
using namespace std;
#define light ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define cases() ll t;cin>>t;while(t--)
#define all(c) c.begin(),c.end()
#define PI 3.14159265358979323846
const ll MAX = 2e5+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;
 
int main()
{
    ll i,j,k,l,p,q,x,y,n;
    cin >> n >> k;multiset<ll> s;
    for(i=0;i<k;i++)
        s.insert(0);
    vector<pair<ll,ll>> vc;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        vc.push_back({y,x});
    }
    sort(all(vc));l = 0;
    for(i=0;i<n;i++)
    {
        x = vc[i].second;
        if(x>=(*s.begin()))
        {
            auto z = s.upper_bound(x);
            if(z==(s.begin()))
                continue;
            z = prev(z);s.insert(vc[i].first);s.erase(z);l++;
        }
    }
    cout << l;
}