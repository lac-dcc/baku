#include<bits/stdc++.h>
using namespace std;
int diri[]={1,-1,0,0};
int dirj[]={0,0,1,-1};
long long cnt=0;
int n,m;
 
void dfs(vector<vector<char>>&a,int i,int j,vector<vector<int>>&vis)
{
 
    if(i>=n||i<0||j<0||j>=m)
        return ;
 
    vis[i][j]=1;
    //cout<<i<<" "<<j<<endl;
    for(int k=0;k<4;k++)
    {
    int x=i+diri[k];
    int y=j+dirj[k];
    if(x>=n||x<0||y<0||y>=m)continue;
    if(!(vis[x][y])&&a[x][y]=='.')
    {
     dfs(a,x,y,vis);
    }
    }
    return;
}
int main()
{
 
 cin>>n>>m;
 vector<int>em={};
 vector<char>emp={};
 vector<vector<int>>vis(n,em);
 vector<vector<char>>a(n,emp);
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
        vis[i].push_back(0);
        char c;
        cin>>c;
        a[i].push_back(c);
 
     }
 
 }
 
 
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<m;j++)
      {
    if(a[i][j]=='.'&&vis[i][j]==0){cnt++;
       dfs(a,i,j,vis);}
      }
 }
 /* for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
        cout<<vis[i][j]<<" ";
 
 
     }
 cout<<"\n";
 }
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
        cout<<a[i][j]<<" ";
 
 
     }
 cout<<"\n";
 }
  for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
        cout<<vis[i][j]<<" ";
 
 
     }
 cout<<"\n";
 }*/
 cout<<cnt<<endl;
}
