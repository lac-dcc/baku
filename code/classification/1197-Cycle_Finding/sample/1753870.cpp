#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
vector<pair<ll, ll> > g[2501];
int vis[2501],par[2501];
int zzz,yyy;
ll d[2501];
 
void dfs(int s)
{
    vis[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        int v=g[s][i].first;
        if(vis[v]==0)
        {
            d[v]=d[s]+g[s][i].second;
            par[v]=s;
            dfs(v);
        }
        else if(v==yyy&&d[v]>d[s]+g[s][i].second)
        {
            zzz=s;
            return;
        }
    }
}
 
void path(int s)
{
    if(par[s]==yyy)
    {
        cout<<par[s]<<" "<<s<<" ";
    }
    else
    {
        path(par[s]);
        cout<<s<<" ";
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }
 
    for(int i=1; i<=n; i++)
    {
        d[i]=1000000000000000000;
        par[i]=i;
    }
    d[1]=0;
    int ck=0,p;
    for(int i=1; i<=n; i++)
    {
        ck=0;
        for(int j=1; j<=n; j++)
        {
            for(int k=0; k<g[j].size(); k++)
            {
                int v=g[j][k].first;
                if(d[v]>d[j]+g[j][k].second)
                {
                    d[v]=d[j]+g[j][k].second;
                    par[v]=j;
                    ck=1;
                    yyy=v;
 
                }
            }
        }
    }
    if(ck==1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            yyy=par[yyy];
        }
        path(yyy);
        //cout<<yyy<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
 
    return 0;
}
 
 
 
