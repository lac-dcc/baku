#include<bits/stdc++.h>
 
using namespace std;
map<int,vector<int>> adj;
 
int farthest = 0;
int mx_dist = 0;
 
 
void dfs(int u,int p, int dist) {
	
 
	for(int& v : adj[u]) {
		if(v == p) continue;
		
		dfs(v,u,dist+1);
		
	}
 
	if(dist > mx_dist) mx_dist = dist, farthest = u;
}
int main() {
	
	
	int n;
	cin >> n;
 
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;
 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,-1,0);
	dfs(farthest,-1,0);
	
	cout <<  mx_dist <<"\n";
	
	return 0;
}
