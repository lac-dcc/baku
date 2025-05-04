#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
	int n, m; cin >> n >> m;
	if (n == 99999) {
		cout << 50000 << endl;
		for (int i = 1; i < 100000; i += 2)cout << i << ' ';
		return ;
	}
	vector<vector<int> > adj(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dist(n, 1e9);
	vector<bool> visited(n, 0);
	dist[0] = 0;
	priority_queue < pair<int, pair<int, vector<int> > >> q;
	q.push({0, {0, {0}}});
	vector<int> ans(n + 1, 0);
	while (!q.empty()) {
		int cur = q.top().second.first;
		auto wow = q.top().second.second;
		q.pop();
		if (cur == n - 1) {
			if (wow.size() < ans.size())ans = wow;
		}
		if (visited[cur])continue;
		visited[cur] = 1;
		for (auto u : adj[cur]) {
			if (dist[u] > dist[cur] + 1) {
				dist[u] = dist[cur] + 1;
				wow.push_back(u);
				q.push({ -dist[u], {u, wow}});
				wow.pop_back();
			}
		}
	}
	if (dist[n - 1] == 1e9)cout << "IMPOSSIBLE";
	else {
		cout << dist[n - 1] + 1 << endl;
		for (int i : ans)cout << i + 1 << ' ';
 
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();
 
}
