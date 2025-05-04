
#include <bits/stdc++.h>
#define ln cout<<endl
#define ll long long 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define f(a,b) for(int i=a;i<b;i++)
#define vin vector<int>
#define vll vector<long long>
using namespace std;
 vector<string>v; 
bool vis[1000][1000];
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
int n,m,cnt=0;
bool valid(int i,int j)
{
	if(vis[i][j]) return false;
	if(i>=0 and i<n and j>=0 and j<m) return true;
	return false;
	
}
void dfs(int i,int j)
{
	vis[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int fx=i+x[k];
		int fy=j+y[k];
		if(valid(fx,fy) && v[fx][fy]=='.')
		{
			dfs(fx,fy);
		}
	}
	
}
 
 
int main()
{
	 
	 cin>>n>>m;
	 string s;
	
	 for(int i=0;i<n;i++)
	 {
	 	cin>>s;
	 	v.push_back(s);
	 	//cout<<v[i]<<endl;
	 }
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(vis[i][j]==false && v[i][j]=='.')
	 		{
	 			dfs(i,j);
	 			cnt++;
	 		}
	 	}
	 }
	 cout<<cnt<<endl;
	 
	
	
	return 0;
}
