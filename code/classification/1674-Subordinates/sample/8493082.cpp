#include<bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5 + 1;
int sz[MAX_N];
vector<int> adj[MAX_N];
int dfs(int u) {
	if (adj[u].size() == 0)
		return 1;
	for (int v : adj[u])
		sz[u] += dfs(v);
	return sz[u] + 1;
}	
 
void solve() {
	int n;	cin >> n;
	for (int i = 2; i <= n; i++) {
		int u;	cin >> u;
		adj[u].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << sz[i] << ' ';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
