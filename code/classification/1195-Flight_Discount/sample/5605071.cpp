#include <bits/stdc++.h>
#define ll long long int 
#define pii pair<ll,pair<ll,ll>> 
using namespace std;
 
int main() 
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> dist1(n+1,LLONG_MAX);
    vector<ll> dist2(n+1,LLONG_MAX);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<pii,vector<pii>,greater<pii>> tmp;
    dist1[1] = 0;
    dist2[1] = 0;
    tmp.push({0,{0,1}});
    tmp.push({0,{1,1}});
    while(!tmp.empty())
    {
        ll node = tmp.top().second.second;
        ll opt = tmp.top().second.first;
        ll dd = tmp.top().first;
        tmp.pop();
        if(opt==0 && dist1[node]<dd)
        continue;
        if(opt==1 && dist2[node]<dd)
        continue;
        for(auto it:adj[node])
        {
            if(opt==1 && ( dd + it.second < dist2[it.first]))
            {
                dist2[it.first] = dd + it.second;
                tmp.push({dist2[it.first],{1,it.first}});
            }
            if(opt==0 && (dd + it.second < dist1[it.first]))
            {
                dist1[it.first] = dd + it.second;
                tmp.push({dist1[it.first],{0,it.first}});
            }
            if(opt==0 && (dd + (it.second/2) < dist2[it.first]))
            {
                dist2[it.first] = dd + (it.second/2);
                tmp.push({dist2[it.first],{1,it.first}});
            }
        }
    }
    
    
    ll ans = min(dist1[n],dist2[n]);
    cout<<ans<<endl;
    return 0;
}
