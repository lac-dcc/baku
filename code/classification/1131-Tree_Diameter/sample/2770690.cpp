#include <bits/stdc++.h>
using namespace std;
 
const int N = (int) 2e5 + 5; 
 
vector <int> adj[N]; 
int dist[N]; 
bool visited[N]; 
int mx_dist, vertex; 
 
void reset() {
	memset(visited, 0, sizeof visited); 
	memset(dist, 0, sizeof dist); 
}
 
void dfs(int u) {
	visited[u] = true; 
	
	for (auto v : adj[u]) {
		if (!visited[v]) {
			dist[v] = dist[u] + 1; 
			
			if (mx_dist < dist[v]) {
				mx_dist = dist[v]; 
				
				vertex = v; 
			}
			
			dfs(v); 
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; 
	cin >> n; 
	
	for (int i = 1; i <= n - 1; i++) {
		int u, v; 
		cin >> u >> v; 
		
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	
	mx_dist = 0, vertex = -1; 
	reset(); 
	dfs(1); 
	
	mx_dist = 0;
	reset();  
	dfs(vertex); 
	
	cout << mx_dist; 
}
 
