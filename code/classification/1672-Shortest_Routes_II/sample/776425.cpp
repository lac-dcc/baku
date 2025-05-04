#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
  bool flag=false;
/*void dfs(int x)
{
    int y=(ans[x]==1)? 2: 1;
    for(int i=0;i<v[x].size()&&!flag;i++)
        {
           if(ans[v[x][i]]==ans[x])
           {
               cout<<"IMPOSSIBLE";
               flag=true;
               break;
           }
            if(ans[v[x][i]]==0)
           {
               ans[v[x][i]]=y;
               dfs(v[x][i]);
           }
        }
 
}*/
int main()
{
 ll n,k,x,l,r,i,m,sum=0,y,sx,sy,ex,ey;
 cin>>n>>k>>r;
 vector <vector <ll> > v(n,vector <ll> (n,1e18));
 vector <ll> ans(n,-1);
 vector <bool> vis(n,false);
  for(int i=0;i<k;i++)
  {
      cin>>x>>y>>l;
      x--;y--;
      v[x][y]=min(l,v[x][y]);
      v[y][x]=min(l,v[y][x]);
  }
  for(int i=0;i<n;i++)
    v[i][i]=0;
 
  for(int k=0;k<n;k++)
  {
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
               if(v[i][k]+v[k][j]<v[i][j])
                    v[i][j]=v[i][k]+v[k][j];
          }
      }
  }
 while(r--)
 {
    cin>>x>>y;
    x--;y--;
    if(v[x][y]>=1e18)
    cout<<-1<<"\n";
    else
        cout<<v[x][y]<<endl;
 }
 
}
