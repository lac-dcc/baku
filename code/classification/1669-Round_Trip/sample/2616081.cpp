#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200008];
int n,vis[200008],col[200008];
vector<int>parent(200008,-1);
int cycle_start,cycle_end;
bool dfs(int v, int par)
{
	vis[v]=1;
	for(int u:adj[v]){
		if(u==par)continue;
		if(vis[u]){
			cycle_end=v;
			cycle_start=u;
			return true;
		}
		parent[u]=v;
		if(dfs(u,parent[u]))
		return true;
	}
	return false;
}
void find_cycle()
{
	cycle_start=-1;
	for(int i=1; i<=n; i++){
		if(vis[i]==0&&dfs(i,parent[i])==true)
		break;
	}
	cout<<endl;
	if(cycle_start==-1)
	cout<<"IMPOSSIBLE\n";
	else{
		vector<int>cycle;
		cycle.push_back(cycle_start);
		for(int i=cycle_end; i!=cycle_start; i=parent[i])
		cycle.push_back(i);
		reverse(cycle.begin(),cycle.end());
		cout<<cycle.size()+1<<endl;
		cout<<cycle_start<<" ";
		for(int v:cycle)cout<<v<<" ";
	}
}
int main()
{
	int m,a,b;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	find_cycle();
	return 0;
}
