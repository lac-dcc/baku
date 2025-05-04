#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
queue<int> q;
vector<int> dist;
vector<int> path;
vector<int> parent;
void trace(int node)
{
	if(parent[node]==-1)
	return;
	path.push_back(parent[node]);
	 trace(parent[node]);
}
int main() {
	int i,n,m;
	cin>>n>>m;
	adj.resize(n);
	dist.resize(n);
	parent.resize(n,-1);
	vector<int> vis;
	vis.resize(n,0);
	//int s=0;f=n-1;
	for(i=0;i<m;i++)
   {
	int u,v;
	cin>>u>>v;
	u--;v--;
	adj[u].push_back(v);
	adj[v].push_back(u);
/*	if(u>v)
	{
		parent[u]=v;
	}
	else
	parent[v]=u;
*/	
    }
   q.push(0);
   vis[0]=1;
   dist[0]=1;
   while(!q.empty())
   {
   	int x=q.front();
   	vis[x]=1;
   	q.pop();
   	for(auto ch:adj[x])
   	{
   		if(vis[ch]==0)
   		{
   			q.push(ch);
   			vis[ch]=1;
   			dist[ch]=dist[x]+1;
   			parent[ch]=x;
   		}
   	}
   }
if(dist[n-1]==0)
{
cout<<"IMPOSSIBLE";
}
else
{
   path.push_back(n-1);
   trace(n-1);
   reverse(path.begin(),path.end());
   cout<<dist[n-1]<<"\n";
   for(i=0;i<path.size();i++)
   {
   	cout<<path[i]+1<<" ";
  // 	cout<<dist[i]<<" ";
   	//cout<<parent[i]<<" ";
   }
}
	// your code goes here
	return 0;
}
