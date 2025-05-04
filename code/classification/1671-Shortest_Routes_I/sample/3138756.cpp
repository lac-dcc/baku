#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
ll mod=1e9+7;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll expo_mod(ll x, ll y)
{
    ll res = 1; // Initialize result
 
    while (y > 0)
    {
        if (y & 1)
            (res = res * x)%=mod;
 
        y = y >> 1; // y = y/2
        (x = x * x)%=mod;  // Change x to x^2
    }
    return res;
}
ll mod_inv(ll a,ll m)
{
    ll ans=expo_mod(a,m-2);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,x,y,c;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> vec1(n+1);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>c;
        vec1[x].push_back({y,c});
    }
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater <pair<ll,ll>>> q1;
    q1.push({0,1});
    while (!q1.empty())
    {
        auto q= q1.top();
        q1.pop();
        ll d=q.first;
        ll v=q.second;
        if(d>dist[v])
            continue;
        
        for(auto u:vec1[v])
        {
            if(dist[u.first]>dist[v]+u.second)
            {
                dist[u.first]=dist[v]+u.second;
                q1.push({dist[u.first],u.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<"\n";
    return 0;
}
