#include <iostream>
#include <vector>
 
using std::cout;
using std::endl;
using std::vector;
 
constexpr long long BIG = 1e18;
 
int main() {
	int n, m, q;
	std::cin >> n >> m >> q;
 
	vector<vector<long long>> min_dist(n, vector<long long>(n, BIG));
	for (int i = 0; i < m; i++) {
		int a, b;
		int c;
		std::cin >> a >> b >> c;
		a--;
		b--;
		if (c < min_dist[a][b]) { min_dist[a][b] = min_dist[b][a] = c; }
	}
 
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long new_dist = min_dist[i][k] + min_dist[k][j];
				if (new_dist < min_dist[i][j]) {
					min_dist[i][j] = min_dist[j][i] = new_dist;
				}
			}
		}
	}
 
	for (int i = 0; i < q; i++) {
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		if (a == b) {
			min_dist[a][b] = 0;
		} else if (min_dist[a][b] == BIG) {
			min_dist[a][b] = -1;
		}
 
		cout << min_dist[a][b] << '\n';
	}
}
