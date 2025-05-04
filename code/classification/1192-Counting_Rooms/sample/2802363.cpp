#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isSafe(int i, int j, int n, int m)
{
     return i>=0&&j>=0&&i<n&&j<m;
}
void dfs(int i,int j,vector<vector<char>>& mat,int n,int m)
{
     if(!isSafe(i,j,n,m))
     return ;
     
     if(mat[i][j]=='#')
     return ;
     
     mat[i][j]='#';
     
     int X[]={1,-1,0,0};
     int Y[]={0,0,-1,1};
     
     for(int k=0; k<4; k++)
     {
         dfs(i+Y[k],j+X[k],mat,n,m);
     }
}
int main() 
{
	ll n,m;
	cin>>n>>m;
	
	vector<vector<char>> mat(n, vector<char>(m));
	char in;
	
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<m; j++)
	    {
	        cin>>in;
	        mat[i][j]=in;
	    }
	}
	
	int cnt=0;
	for(int i=0; i<n; i++)
	{
	    for(int j=0; j<m; j++)
	    {
	        if(mat[i][j]=='#')
	        continue;
	        
	        cnt++;
	        dfs(i,j,mat,n,m);
	    }
	}
	cout<<cnt;
}
