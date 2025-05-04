#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#endif
 
const int MAXN = 1e5 + 10;
 
vector<int> adj[MAXN];
vector<int> label(MAXN, -1);
bool ok = true;
 
void dfs(int v, int c) {
	label[v] = c;
	for (auto && u : adj[v]) {
		if (label[u] != -1) {
			ok = ok && label[u] != c;
			continue;
		}
		dfs(u, c % 2 + 1);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (label[i] == -1) {
			dfs(i, 1);
		}
	}
	if (ok) {
		for (int i = 0; i < n; ++i) {
			cout << label[i] << " \n"[i == n - 1];
		}
	}
	else {
		cout << "IMPOSSIBLE" << '\n';
	}
}
