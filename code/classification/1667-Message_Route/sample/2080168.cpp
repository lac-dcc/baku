#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
vector<ll>v[N];
ll dis[N];
ll vis[N];
void bfs(ll d)
{
    vis[d]=1;
    queue<ll>q;
    q.push(d);
    dis[d]=0;
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        for(ll child:v[cur])
        {
            if(vis[child]==0)
            {
              q.push(child);
              dis[child]=dis[cur]+1;
              vis[child]=1;
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    if(dis[n]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<ll>r;
        ll d=dis[n],f;
        r.push_back(n);
        f=n;
        while(d>0)
        {
            d--;
            for(ll child:v[f])
            {
                if(dis[child]==d)
                {
                    r.push_back(child);
                    f=child;
                    break;
                }
 
            }
        }
        cout<<dis[n]+1<<endl;
        for(int i=r.size()-1;i>=0;i--)
        {
            cout<<r[i]<<" ";
        }
        cout<<endl;
 
    }
 
 
}
