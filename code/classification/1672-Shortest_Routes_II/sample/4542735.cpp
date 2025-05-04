#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=700;
const ll INF=1e12+7;
vector<pair<int,int> >adj[N];
ll dis[N][N];
 
ll minn(ll a,ll b)
{
  if(a<b)
  return a;
  else
  return b;
}
 
 
void solve()
{
   int n,m,q;
   cin>>n>>m>>q;
    
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
      dis[i][j]=INF;
    }
   }
 
 
   while(m--)
   {
    int a,b,w;
    cin>>a>>b>>w;
    dis[a][b]=minn(dis[a][b],w);
    dis[b][a]=minn(dis[b][a],w);
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
   }
 
 
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
       if(i==j)
       dis[i][j]=0;
    }
   }
 
   //Initialization and inputs other than quiries is done 
   //Apply Floyd Warshall ALgorithm 
 
   for(int k=1;k<=n;k++)
   {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(dis[i][k]!=INF&&dis[k][j]!=INF)
        dis[i][j]=minn(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
   }
   //Printing q queries 
   while(q--)
   {
    int a,b; cin>>a>>b;
    if(dis[a][b]==INF)
    cout<<-1<<endl;
    else
    cout<<dis[a][b]<<endl;
   }
}
 
int main()
{
  int t=1;//cin>>t;
 
  while(t--)
  {
   solve();
  }
}
 
