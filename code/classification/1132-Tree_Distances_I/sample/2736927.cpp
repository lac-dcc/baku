// source -> https://cses.fi/problemset/task/1132/
 
#include<bits/stdc++.h>
using namespace std;
 
#define FIO ios::sync_with_stdio(0); cin.tie(0);
 
 
vector<int> adj[200001];
int d1[200001];  // to store first-max length.
int d2[200001]; // to store second-max length.
int c[200001]; // to store child for path of max length.
 
void dfs(int v, int p) {
	d1[v] = 0;
	d2[v] = 0;
	for (auto x : adj[v]) {
		if (x == p)continue;
		dfs(x, v);
		if (d1[x] + 1 > d1[v]) {
			d2[v] = d1[v];
			d1[v] = d1[x] + 1;
			c[v] = x;
		}
		else if (d1[x] + 1 > d2[v]) {
			d2[v] = d1[x] + 1;
		}
	}
}
 
void dfs2(int v, int p) {
	for (auto x : adj[v]) {
		if (x == p) continue;
		if (c[v] == x) {
			if (d1[x] < d2[v] + 1) {
				d2[x] = d1[x];
				d1[x] = d2[v] + 1;
				c[x] = v;
			}
			else {
				d2[x] = max(d2[x], d2[v] + 1);
			}
		}
		else {
			d2[x] = d1[x];
			d1[x] =  d1[v] + 1;
			c[x] = v;
		}
		dfs2(x, v);
	}
}
 
int main() {
	FIO;
	int n, u, v;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// METHOD-I- All longest paths-given in CPH ~~~ (O(n))- 2-DFS
	dfs(1, -1);
	dfs2(1, -1);
 
	for (int i = 1; i <= n; i++) {
		cout << d1[i] << " ";
	}
	return 0;
}
