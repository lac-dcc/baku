#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
int cor[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> parent;
int32_t main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adjlist(n);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adjlist[a-1].push_back({b-1,c});
	}	
	vector<int> distance(n,LLONG_MAX);
	vector<int> visited(n,0);
	distance[0]=0;
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	pq.push({0,0});
	while(!pq.empty())
	{
		auto tp=pq.top();
		pq.pop();
		int dist=tp.first;
		int x=tp.second;
		if(visited[x]==1)
		continue;
		visited[x]=1;
		for(auto &edg:adjlist[x])
		{
			if(distance[x]+edg.second<distance[edg.first])
			{
				distance[edg.first]=distance[x]+edg.second;
				pq.push({distance[x]+edg.second,edg.first});
			}
		}
	}
	for(int i=0;i<distance.size();i++)
	{
		cout<<distance[i]<<" ";
	}
}
