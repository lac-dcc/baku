#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007;
 
int n,m;
const int maxn=10000;
vector<vector<int>>edges;
vector<int>dis;
vector<int>par;
 
 
void bellman_ford()
{
	int x;
	for(int i=0;i<n;i++)
	{
		x=-1;
		for(int j=0;j<m;j++)
		{
			int u=edges[j][0],v=edges[j][1],w=edges[j][2];
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				par[v]=u;
				x=v;
			}
		}
	}
	if(x==-1)cout<<"NO\n";
	else
	{
		for(int i=0;i<n;i++)
		x=par[x];
		
		vector<int>ans;
		for(int v=x;;v=par[v])
		{
			ans.push_back(v);
			if(v==x&&ans.size()>1)
			break;
		}
		reverse(ans.begin(),ans.end());
		cout<<"YES\n";
		for(auto i:ans)cout<<i<<" ";
		cout<<"\n";
	}
}
 
 
signed main()
{
	cin>>n>>m;
	dis.resize(n+1);
	par.resize(n+1,-1);
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({a,b,c});
	}
	bellman_ford();
	
}
 
