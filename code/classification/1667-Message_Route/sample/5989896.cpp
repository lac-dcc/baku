#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
 
	#ifndef ONLINE_JUDGE
		//for getting input from input.txt
	freopen("input.txt","r",stdin);
		//for writing output to output.txt
	freopen("output.txt","w",stdout);
	#endif
 
	int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	vector<int>dis(n,1e9);
	queue<pair<int,int>>q;
 
	vector<int>parent(n);
 
	q.push({0,0});	//{distance,node}
	dis[0]=0;
	parent[0]=-1;
 
	while(q.size())
	{
		int d=q.front().first;
		int node=q.front().second;
		q.pop();
 
		for(auto it:adj[node])
		{
			if(d+1<dis[it])
			{
				parent[it]=node;
				dis[it]=d+1;
				q.push({d+1,it});
			}
		}
	}
	if(dis[n-1]==1e9)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0; 
	}
 
	int k=n-1;
	vector<int>route;
 
	while(parent[k]!=-1)
	{
		route.push_back(k);
		k=parent[k];
	}
	route.push_back(k);
 
	reverse(route.begin(), route.end());
	cout<<route.size()<<endl;
	for(int i=0;i<route.size();i++)
	{
		cout<<route[i]+1<<" ";
	}
 
}
 
