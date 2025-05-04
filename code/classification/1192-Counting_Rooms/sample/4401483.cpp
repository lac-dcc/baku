#include <bits/stdc++.h>
using namespace std;
 
char **a;bool **visited;
void dfs(int i,int j,int n,int m)
{
	if(visited[i][j])
	return;
	else
	{
		visited[i][j]=true;
		if((i-1>=0 && a[i-1][j]=='.'))
		dfs(i-1,j,n,m);
		if((i+1<=n-1 && a[i+1][j]=='.'))
		dfs(i+1,j,n,m);
		if((j-1>=0 && a[i][j-1]=='.'))
		dfs(i,j-1,n,m);
		if((j+1<=m-1 && a[i][j+1]=='.'))
		dfs(i,j+1,n,m);
		
	}
}
 
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	// char a[n][m];
	a=new char*[n];
	visited=new bool*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new char[m];
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
	{	cin>>a[i][j];visited[i][j]=false;}
	}
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j] && a[i][j]=='.')
			{
				dfs(i,j,n,m);
				c++;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
