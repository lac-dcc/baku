#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
void dfs(vector <int> adj[],int i,vector <int>& vis){
	if(vis[i]) return;
	vis[i] = 1;
	for(auto j : adj[i]){
		if(!vis[j]){
			dfs(adj,j,vis);
		}
	}
	return;
}
 
int main(){
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <int> adj[n];
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	vector <int> vis(n,0);
	vector <int> bet;
	for(int i = 0;i < n;i++){
		if(!vis[i]){
			dfs(adj,i,vis);
			bet.push_back(i + 1);
		}
	}
	cout << bet.size() - 1 << endl;
	for(int i = 0;i < bet.size() - 1;i++){
		cout << bet[i] << " " << bet[i + 1] << "\n";
	}
	return 0;
}
