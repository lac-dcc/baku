#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 1e5;
int n, m, c[mxN];
vector<int> adj[mxN], ans;
bool vis[mxN];
 
void dfs(int u, int cu = 0){
	if(c[u] >= 0){
		if(c[u]^cu){
			cout << "IMPOSSIBLE";
			exit(0);
		}
		return; 
	}
	c[u] = cu;
	for(int v : adj[u]){
		dfs(v, cu^1);
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0, a, b; i < m; ++i){		
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(c, -1, 4*n);
	for(int i = 0; i < n; ++i){
		if(c[i] < 0){
			dfs(i);
		}
	}
	for(int i = 0; i < n; ++i){
		cout << c[i] + 1 << " ";
	}
	
}
