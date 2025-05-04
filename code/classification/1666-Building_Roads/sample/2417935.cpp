#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
vector <int> adj[200001];
bool visited[200001];
void dfs(int node){
	visited[node]=true;
	for(auto i:adj[node]){
		if(visited[i])
			continue;
		dfs(i);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	int i;
 
	for(i=0;i<=n;i++)
		adj[i].clear();
	for(i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans1;
	int x=0;
	vector <pair<int,int>> p;
	memset(visited,false,sizeof(visited));
	for(i=1;i<=n;i++)
	{
		if(visited[i])
			continue;
		if(x>=1)
			p.push_back(make_pair(ans1,i));
		ans1=i;
		dfs(i);	
		x++;
	}
	cout<<p.size()<<"\n";
	for(auto it:p){
		cout<<it.first<<" "<<it.second<<"\n";
	}
}
