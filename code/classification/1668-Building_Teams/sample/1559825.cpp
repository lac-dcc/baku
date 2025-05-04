#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[100006];
vector<bool> visited(100006, false);
vector<int> ans(100007);
 
/* first pass */
 
bool dfs(int i, int c) {
	visited[i] = 1;
	ans[i] = c;
	
	for (auto& e : adj[i]) {
		if (visited[e]) {
			if (ans[i] == ans[e]) return false;
		}
		
		else {
			if (dfs(e, c ^ 1) == false) return false;
		}
	}
	return true;
}
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
 
	fill(begin(visited), end(visited), false);
 
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			auto bip = dfs(i, 1);
			if (!bip) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
 
	for (int i = 1; i <= n; i++) cout << ans[i] + 1 << " ";
 
	return 0;
}
