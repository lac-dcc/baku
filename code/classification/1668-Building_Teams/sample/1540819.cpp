#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n+1);
	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> color(n+1, -1);
	for(int i = 1; i <= n; ++i) {
		if(color[i] >= 0) continue;
		queue<pair<int,int>> q;
		q.push({i, 0});
		while(!q.empty()) {
			pair<int,int> p = q.front(); q.pop();
			if(color[p.first] >= 0 && color[p.first] != p.second) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			if(color[p.first] >= 0) continue;
			color[p.first] = p.second; 
			for(int to : edges[p.first]) {
				q.push({to, p.second ^ 1});
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		cout << color[i]+1 << ' ';
	}
}
