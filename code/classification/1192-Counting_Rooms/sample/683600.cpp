#include<bits/stdc++.h>
using namespace std;
int xdir[4]={0,0,1,-1};
int ydir[4]={1,-1,0,0};
 
vector<vector<char> > a;
vector<vector<int> > visited;
bool isvalid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
 
void dfs(int i,int j,int n,int m)
{
    visited[i][j]=1;
    for(int k=0;k<4;k++)
    {
        int x=i+xdir[k];
        int y=j+ydir[k];
        if(isvalid(x,y,n,m)&&!visited[x][y]&&a[x][y]=='.')
        {
            dfs(x,y,n,m);
        }
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    a.resize(n,vector<char> (m));
    visited.resize(n,vector<int> (m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j]&&a[i][j]=='.')
            {
                dfs(i,j,n,m);
                ct++;
            }
 
        }
    }
    cout<<ct<<endl;
 
}
