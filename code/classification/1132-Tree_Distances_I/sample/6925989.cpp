#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define pb push_back
#define all(a) a.begin(),a.end()
#define fore(n) for(int i=0;i<n;i++)
#define f first
#define s second
 
const int INF = 1e9;
 
vi adj[200001];
vi in,out;
 
void dfs1(int v,int p)
{
    in[v]=0;
    for(auto u:adj[v])
    {
        if(u!=p)
        {
            dfs1(u,v);
            in[v]=max(in[v],1+in[u]);
        }
    }
}
 
void dfs2(int v, int p)
{
    int max1=-1,max2=-1;
    for(auto u: adj[v])
    {
        if(u==p) continue;
        if (in[u]>= max1)
        {
            max2=max1;
            max1=in[u];
        }
        else if(in[u]>max2)
        {
            max2=in[u];
        }
    }
    for(auto u: adj[v])
    {
        if(u==p) continue;
        int longest=max1;
 
        if(max1==in[u])
        {
            longest=max2;
        }
        out[u]=1+max(out[v],1+longest);
 
        dfs2(u,v);
 
    }
 
}
 
 
int main()
{
    int n;
    cin>>n;
    fore(n-1)
    {
        int v,u;
        cin>>v>>u;
        v--;u--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    in.assign(n,0);
    out.assign(n,0);
    dfs1(0,-1);
    dfs2(0,-1);
    vi ans(n);
    fore(n) ans[i]=max(in[i],out[i]);
    fore(n) cout<<ans[i]<<" ";
    return 0;
}
