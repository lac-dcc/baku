#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
int vis[100001];
vector<int> g[100001];
int par[100001];
vector<int> cou;
int d[100001];
int n,m,rel,res,z=0;
int ck=0;
 
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        int v=g[s][i];
        if(vis[v]==0)
        {
            par[v]=s;
            dfs(v);
        }
        else if(par[s]!=v)
        {
            ck=1;
            rel=s;
            res=v;
        }
    }
}
 
void path(int s)
{
    if(par[s]==rel)
    {
        z+=3;
        cout<<z<<endl;
        cout<<par[s]<<" "<<s<<" ";
    }
    else
    {
        z++;
        path(par[s]);
        cout<<s<<" ";
    }
}
 
int main()
{
 
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<=n;i++)
    {
        vis[i]=0;
        par[i]=i;
        d[i]=1000001;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
        if(ck==1)
            break;
    }
 
 
    if(ck==1)
    {
        path(res);
        cout<<rel<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
 
    return 0;
}
 
