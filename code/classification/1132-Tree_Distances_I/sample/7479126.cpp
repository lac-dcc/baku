#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[200001];
int firstMax[200001];   // to store first-max length.
int secondMax[200001];  // to store second-max length.
int c[200001];          // to store child for path of max length.
 
// calculate for every node x the maximum
// length of a path that goes through a child of x
void dfs(int v, int p) {
	firstMax[v] = 0;
	secondMax[v] = 0;
	for (auto x : adj[v]) {
		if (x == p) continue;
		dfs(x, v);
		if (firstMax[x] + 1 > firstMax[v]) {
			secondMax[v] = firstMax[v];
			firstMax[v] = firstMax[x] + 1;
			c[v] = x;
		} else if (firstMax[x] + 1 > secondMax[v]) {
			secondMax[v] = firstMax[x] + 1;
		}
	}
}
 
// calculate for every node x the
// maximum length of a path through its parent p
void dfs2(int v, int p) {
	for (auto x : adj[v]) {
		if (x == p) continue;
		if (c[v] == x) {
			if (firstMax[x] < secondMax[v] + 1) {
				secondMax[x] = firstMax[x];
				firstMax[x] = secondMax[v] + 1;
				c[x] = v;
			} else {
				secondMax[x] = max(secondMax[x], secondMax[v] + 1);
			}
		} else {
			secondMax[x] = firstMax[x];
			firstMax[x] = firstMax[v] + 1;
			c[x] = v;
		}
		dfs2(x, v);
	}
}
 
int main() {
	int n, u, v;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
 
	for (int i = 1; i <= n; i++) { cout << firstMax[i] << " "; }
	return 0;
}
