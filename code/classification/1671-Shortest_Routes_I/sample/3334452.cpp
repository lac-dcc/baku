#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
#define endl "\n"
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loopf(i,a,b) for(ll i=a;i<=b;i++)
#define print(a) for(auto i:a) cout<<i<<" ";
const int mod = 1e9+7;
ll power(ll x,ll y)
{
    x=x%mod,y=y%mod;
    if(y==0) return 1;
    ll temp=power(x,y/2)%mod;
    ll result =(temp*temp)%mod;
    if(y%2==1) result=(result*x)%mod;
    return result;
}
 
 
 
int main()
{
    fast
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adjlist[n+1];
    vector<ll>shortdist(n+1,1e18),visited(n+1);
    while(m--)
    {
        ll u,v,d;
        cin>>u>>v>>d;
        adjlist[u].push_back({v,d});
    }
    shortdist[1]=0;
    set<pair<ll,ll>>s;
    for(ll i=1;i<=n;i++)
    s.insert({shortdist[i],i});
    while(!s.empty())
    {
        auto u=s.begin()->second;
        auto dist=s.begin()->first;
        visited[u]=1;
        s.erase(s.begin());
        for(auto j:adjlist[u])
        {
            if(shortdist[j.first]>shortdist[u]+j.second)
            {
               s.erase({shortdist[j.first],j.first});
               shortdist[j.first]=shortdist[u]+j.second; 
               s.insert({shortdist[j.first],j.first});
            }
        }
    }
    for(ll i=1;i<=n;i++)
    cout<<shortdist[i]<<" ";
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
