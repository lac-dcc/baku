#define ll long long
#include <bits/stdc++.h>
 
const ll inf=1e18;
using namespace std;
 
ll n,m,u,v,w,q;
ll d[507][507];
 
void floy()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
 
void reset(ll n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j] = inf;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>q;
    reset(n);
 
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        d[u][v] = min(w,d[u][v]);
        d[v][u] = min(w,d[u][v]);
    }
    floy();
    for(int i=0;i<q;i++)
    {
        cin>>u>>v;
        if(d[u][v] == inf) cout<<"-1"<<"\n";
        else cout<<d[u][v]<<"\n";
    }
}
