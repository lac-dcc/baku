#include<bits/stdc++.h>
using namespace std;
vector<int> g[200001];
vector<int> in;
vector<int> out;
void dfs1(int n,int p)
{
	in[n]=0;
	for(int x:g[n])
	{
		if(x!=p)
		{
			dfs1(x,n);
			in[n]=max(in[n],1+in[x]);
		}
	}
}
void dfs2(int n,int p)
{
	int mx1=-1,mx2=-1;
	for(int x:g[n])
	{
		if(x!=p)
		{
			if(in[x]>=mx1)
			{
				mx2=mx1;
				mx1=in[x];
			}
			else if(in[x] > mx2)
			mx2=in[x];
		}
	}
	
	for(int x:g[n])
	{
		if(x!=p)
		{
			int use=mx1;
			if(in[x]==use)
			use=mx2;
			out[x]=max(1+out[n],2+use);
			dfs2(x,n);
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	in.resize(n+1,0);
	out.resize(n+1,0);
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
	cout<<max(in[i],out[i])<<" ";
}
