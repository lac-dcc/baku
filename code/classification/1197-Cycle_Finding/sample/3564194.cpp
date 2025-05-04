#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,i,j,a,b,c,x,culprit=-1;
	cin>>n>>m;
	vector<pair<pair<ll,ll>,ll>> edges;
	vector<ll> adj[n];
	vector<ll> cycle;
	//ll visited[n]={0};
	vector<ll> visited(n, 0);
	ll parent[n];
	for (i=0;i<n;i++)
		parent[i]=-1;
	for (i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		edges.push_back({{a-1,b-1},c});
		adj[a-1].push_back(b-1);
	}
	ll distance[n];
	for (i=0;i<n;i++)
		distance[i]=LLONG_MAX/10;
	distance[0]=0;
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<m;j++)
		{
			if (distance[edges[j].first.second]>distance[edges[j].first.first]+edges[j].second)
			{
				distance[edges[j].first.second]=distance[edges[j].first.first]+edges[j].second;
				parent[edges[j].first.second]=edges[j].first.first;
			}
		}
	}
	for (j=0;j<m;j++)
	{
		if (distance[edges[j].first.second]>distance[edges[j].first.first]+edges[j].second)
		{
			//distance[edges[j].first.second]=distance[edges[j].first.first]+edges[j].second;
			if (parent[edges[j].first.second]==-1)
				parent[edges[j].first.second]=edges[j].first.first;
			culprit=edges[j].first.first;
			break;
		}
	}
	if (culprit==-1)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for (i=0;i<n;i++)
		culprit=parent[culprit];
	for (i=culprit;;i=parent[i])
	{
		cycle.push_back(i);
		if (i==culprit&&cycle.size()>1)
			break;
	}
	reverse(cycle.begin(),cycle.end());
	for (auto node:cycle)
		cout<<node+1<<" ";
	return 0;
}
