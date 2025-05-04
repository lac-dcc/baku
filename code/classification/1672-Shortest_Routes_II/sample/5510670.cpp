#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<vector<long long>> dist (n, vector<long long> (n, 1e18));
	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}
	for(int i = 0; i < m; i++) {
		long long a, b, c; cin >> a >> b >> c;
		if (dist[a-1][b-1] > c) {
			dist[a - 1][b - 1] = c;
			dist[b - 1][a - 1] = c;
		}
		
	}
	
	for (int w = 0; w < n; w++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (dist[u][w] + dist[w][v] < dist[u][v]) {
					dist[u][v] = dist[u][w] + dist[w][v];
				}
			}
		}
	}
	
	
	for (int i = 0; i < q; i++) {
		long long a, b; cin >> a >> b;
		a--;
		b--;
		if (dist[a][b] < 1e18) {
			cout << dist[a][b] << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
