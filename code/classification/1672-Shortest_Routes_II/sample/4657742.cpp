#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
int flag;
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, LONG_MAX));
	for (int i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = min(adj[b][a], c);
	}
	vector<vector<ll>>dist(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				dist[i][j] = 0;
			else if (adj[i][j])
				dist[i][j] = adj[i][j];
			else
				dist[i][j] = LONG_MAX;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] < LONG_MAX && dist[k][j] < LONG_MAX)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == LONG_MAX)
			cout << -1 << endl;
		else
			cout << dist[a][b] << endl;
 
	}
 
	return 0;
}
