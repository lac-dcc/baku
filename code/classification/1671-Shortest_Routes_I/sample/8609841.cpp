#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,long long> > >adj(n+1);
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
	long long dist[n+1];
	bool flag[n+1];
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	for(int i=0;i<=n;i++)
	{
		dist[i]=9223372036854775807;
		flag[i]=false;
	}
	dist[1]=0;
	pq.push({dist[1],1});
	while(!pq.empty())
	{
		long long d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(flag[u])
		{
			continue;
		}
		flag[u]=true;
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first,w=adj[u][i].second;
			if(!flag[v] && d+w<dist[v])
			{
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
}
/*
3 4
1 2 6
1 3 4
3 2 3
1 3 2
*/
