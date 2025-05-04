#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(a)  a.begin(),a.end() 
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpi vector<pii>
#define vpl vector<pll>
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,x)  for(int i=x;i>=0;i--)
// const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};   //(Graph on 2D-Grid)
// const char dir[4]={'U','L','D','R'};
vi ar[100005],res;
int vis[100005]={0},p[100005];
void dfs(int node,int par)
{
	vis[node]=1;
	p[node]=par;
	for(int ele:ar[node])
	{
		if(ele==par)
		continue;
		if(vis[ele])
		{
			int a=node;
			while(ele^node)
			{
				res.pb(node);
				node=p[node];
			} 
			res.pb(node);
			res.pb(a);
			cout<<res.size()<<endl;
			for(int ele:res)
			cout<<ele<<" ";
			exit(0);
		}
		else
		dfs(ele,node);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	rep(i,1,n+1)
	if(!vis[i])
	dfs(i,-1);
	cout<<"IMPOSSIBLE";
	return 0;
}
