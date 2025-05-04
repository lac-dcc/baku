#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> adj[200005];
int dist[200005];
bool vis[200005];
 
void dfs(int node, int distance) {
	// cout << node << endl;
	dist[node] = distance;
	vis[node] = true;
	for (int i=0; i<adj[node].size(); i++) {
		int other = adj[node][i];
		if (!vis[other]) dfs(other, distance+1);
	}
}
 
int main() {
 
	cin >> n;
	
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	memset(vis, 0, sizeof vis);
	dfs(1, 0);
	
	int mxdist = 0;
	int mxn = 0;
	
	for (int i=1; i<=n; i++) {
		if (dist[i] > mxdist) {
			mxdist = dist[i];
			mxn = i;
		}
	}
	
	memset(vis, 0, sizeof vis);
	dfs(mxn, 0);
	
	for (int i=1; i<=n; i++) {
		mxdist = max(mxdist, dist[i]);
	}
	
	cout << mxdist << endl;
	
}
