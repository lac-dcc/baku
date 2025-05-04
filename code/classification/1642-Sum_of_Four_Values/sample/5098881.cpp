#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef   double ld;
const ll mod=1e9+7;
const ll N=2e5+7;
#define endl '\n'
ll ans[N];
int32_t main()
{
    //freopen("jumping.in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,pair<ll,ll>>>v;
    vector<ll>arr,v1;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a;
        arr.push_back(a);
    }
    //sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            v1.push_back(arr[i]+arr[j]);
            v.push_back({arr[i]+arr[j],{i,j}});
        }
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll o=arr[i]+arr[j];
            if(o>=x)continue;
            ll idx=lower_bound(v1.begin(),v1.end(),x-o)-v1.begin();
            while(idx<v.size()&&v1[idx]==x-o&&(v[idx].second.first==i||v[idx].second.second==i||v[idx].second.second==j||v[idx].second.first==j))
            idx++;
            if(idx<v.size()&&v1[idx]==x-o&&(v[idx].second.first!=i&&v[idx].second.second!=i&&v[idx].second.second!=j&&v[idx].second.first!=j))
            {
                cout<<i+1<<" "<<j+1<<" "<<v[idx].second.first+1<<" "<<v[idx].second.second+1;
                exit(0);
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
 
}