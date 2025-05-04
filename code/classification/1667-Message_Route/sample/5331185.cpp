#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector <vi> g(n+1);
    for(ll i=1; i<=m; i++)
    {
        ll p,q;
        cin>>p>>q;
        g[p].push_back(q);
        g[q].push_back(p);
    }
 
    vector <bool> vis(n+1,0);
    vi dis(n+1,-1);
    dis[1]= 1;
 
    queue<ll> q;
    q.push(1);
    vis[1]=1;
 
    vi order(n+1,0);
 
    while(!q.empty())
    {
        ll t= q.front();
        q.pop();
 
        for(auto x:g[t])
        {
            if(vis[x])
                continue;
            q.push(x);
            order[x]=t;
            dis[x]= dis[t]+1;
            vis[x]=1;
        }
    }
    if(dis[n]==-1) cout<<"IMPOSSIBLE\n";
    else {
        cout<<dis[n]<<"\n";
        vi pa;
        ll a= n;
        while(a!=0)
        {
            pa.push_back(a);
            a= order[a];
        }
        for(ll i= pa.size()-1; i>=0; i--)
            cout<<pa[i]<<" ";
    }
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
 
