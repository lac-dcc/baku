#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
char g[1005][1005];
bool visited[1005][1005];
 
int dx[] = {-1, 0, 1 , 0};
int dy[] = {0, 1,  0, -1};
 
bool isValid(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m)
		return false;
	if(visited[x][y] ||  g[x][y] == '#')
		return false;
	return true;
}
 
void dfs(int x,int y)
{
	visited[x][y]=true;
	for(int i=0;i<4;i++)
	{
		if(isValid(x+dx[i], y+dy[i]))
		dfs(x+dx[i], y+dy[i]);
	}
}
 
int main()
{
    cin>>n>>m;
   
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=m;j++)
       {
          cin>>g[i][j];
       }
    }
    
    int count = 0;
 
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		visited[i][j]=false;
    	}
    }
 
    for(int i=1;i<=n;i++)
    {
    	for(int j=1; j<=m ;j++)
    	{
    		if(!visited[i][j] && g[i][j] == '.')
    	    {
    	    	count++;
    		    dfs(i,j);
    	    }
        }
    }
 
    cout<<count<<endl;
 
	return 0;
}
