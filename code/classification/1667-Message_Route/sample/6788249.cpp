#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x.size())
// #define pii pair<int, int>
#define ai2 array<int, 2>
#define ai3 array<int, 3>
#define f first
#define s second
using namespace std;
 
const int N = 1e5+1;
priority_queue<ai3, vector<ai3>, greater<ai3>> pq;
vector<vector<int>> edges(N);
vector<ai2> dist(N, {-1, -1});
 
void add(int x) {
	for (auto y : edges[x]) {
		pq.push({dist[x][0]+1, y, x});
	}
}
 
void solve() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
 
	dist[n][0] = 0;
	dist[n][1] = 0;
	add(n);
 
	while (!pq.empty()) {
		if (dist[pq.top()[1]][0] == -1) {
			dist[pq.top()[1]] = {pq.top()[0], pq.top()[2]};
			add(pq.top()[1]);
		}
		pq.pop();
	}
 
	// for (int i = 1; i <= n; ++i) {
	// 	cout << dist[i][0] << " ";
	// }
	// cout << "\n";
 
	// for (int i = 1; i <= n; ++i) {
	// 	cout << dist[i][1] << " ";
	// }
	// cout << "\n";
 
	if (dist[1][0] == -1) cout << "IMPOSSIBLE\n";
	else {
		cout << dist[1][0]+1 << "\n";
		x = 1;
		cout << "1 ";
		while (x != n) {
			cout << dist[x][1] << " ";
			x = dist[x][1];
		}
	}
 
	return;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	
	return 0;
}
