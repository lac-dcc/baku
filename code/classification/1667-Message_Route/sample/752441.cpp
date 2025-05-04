#include<bits/stdc++.h>
using namespace std;
void displayAdjList(vector<int> adj_list[], int n)
{
	for(int i = 1; i<=n; i++)
	{
		cout << i << "--->";
		vector<int> :: iterator it;
		for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}
 
 
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	vector<bool> visited(n+1);
	int distance[n+1];
	int a,b;
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//displayAdjList(adj,n);
	queue<pair<int,int> > q;
	list<pair<int,int> > p;
	int x=1;
	visited[x] = true;
	distance[x] = 0;
	q.push(make_pair(x,1));
	p.push_front(make_pair(x,1));
	while (!q.empty())
	{
		int s,cur_level;
		tie(s,cur_level)  = q.front();
		//cout<<"\t\t"<<s<<" "<<cur_level<<endl;
		q.pop();
		for (auto u : adj[s])
		{
			if (visited[u]) continue;
			if(u==n)
			{
				p.push_front(make_pair(u,cur_level+1));
				goto node_reached;
			}
			visited[u] = true;
			distance[u] = distance[s]+1;
			q.push(make_pair(u,cur_level+1));
			p.push_front(make_pair(u,cur_level+1));
		}
	}
node_reached:
	;
	vector<int> path;
	int prev_level=p.front().second;
	int prev_node=n;
	int node,level;
	path.push_back(p.front().first);
	p.pop_front();
	while(!p.empty())
	{
		tie(node,level)=p.front();
		//	cout<<"\t"<<node<<" "<<level<<" "<<prev_node<<" "<<prev_level<<endl;
		if(prev_level-level>0)
			if(find(adj[node].begin(),adj[node].end(),prev_node)!=adj[node].end())
			{
				path.push_back(node);
				prev_level=level;
				prev_node=node;
			}
		p.pop_front();
	}
	if(path.size()>1)
	{
		cout<<path.size()<<endl;
		for(int i=path.size()-1; i>=0; i--)
			cout<<path[i]<<" ";
	}
	else cout<<"IMPOSSIBLE";
}
