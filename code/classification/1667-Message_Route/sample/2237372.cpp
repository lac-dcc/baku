#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
 
bool bfs(vi* graph, int v, int sv, int tv) {
	bool pathFound = false;
	int parent[v];
	for (int i = 0; i < v; i++) parent[i] = -1;
	queue<int> q;
	q.push(sv);
	parent[sv] = sv;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (auto i: graph[curr]) {
			if (parent[i] == -1) {
				parent[i] = curr;
				if (i == tv) {
					pathFound = true;
				}
				q.push(i);
 			}
		}
		if (pathFound) break;
	}
	if (!pathFound) return false;
	vi path;
	int x = tv, length = 0;
	while (parent[x] != x) {
		length++;
		path.push_back(x);
		x = parent[x];
	}
	path.push_back(x);
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for (auto a: path) {
		cout << a + 1 << " ";
	}
	return true;
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int v, e, a, b;
	cin >> v >> e;
	vi graph[v];
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if (!bfs(graph, v, 0, v - 1)) {
		cout << "IMPOSSIBLE" << endl;
	}
 
}
