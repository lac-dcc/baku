#include <bits/stdc++.h>
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
 
#define ll long long
#define ar array
 
const int N = 1e5 + 1;
int n, m, p[N]; //p is the parent array
vector<int> adj[N];
vector<int> ans;
bool vis[N];
 
void dfs(int u, int pu) {
	p[u] = pu;
	vis[u] = 1;
	for (int v : adj[u]) {
		if (v == pu)
			continue;
		if (vis[v]) {
			int u2 = u;
			while (u != v) {
				ans.push_back(u);
				u = p[u];
			}
			ans.push_back(v);
			ans.push_back(u2);
			cout << ans.size() << endl;
			for (int x : ans)
				cout << x << " ";
			exit(0);
		}
		else {
			dfs(v, u);
		}
	}
}
 
int main() {
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, -1);
		}
	}
	cout << "IMPOSSIBLE";
}
