#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll MOD=1e9+7;
 
vector<ll> in,in2,out;
 
void dfs(int s,int p,vector<vector<ll>> &adj)
{
	for(auto i:adj[s])
	{
		if(i!=p)
		{
			dfs(i,s,adj);
			
			if(in[i]+1 > in[s])
			{
				in2[s]=in[s];
				in[s]=in[i]+1;
			}
			else if(in[i]+1 > in2[s])
			{
				in2[s]=in[i]+1;
			}
		}
	}
}
 
void dfs1(int s,int p,vector<vector<ll>> &adj)
{
	for(auto i:adj[s])
	{
		if(i!=p)
		{
			if(in[s]==in[i]+1)
			out[i]=max(in2[s]+1, out[s]+1);
			else
			out[i]=max(out[s]+1,in[s]+1);
			
			dfs1(i,s,adj);
		}
	}
}
 
int main()
{
	ll n;
	cin>>n;
	
	vector<vector<ll>> adj(n+1);
	
	for(int i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	in=in2=out=vector<ll> (n+1);
	
	dfs(1,0,adj);
	
	dfs1(1,0,adj);
	
	for(int i=1;i<=n;i++)
	cout<<max(in[i],out[i])<<" ";
	return 0;
}
