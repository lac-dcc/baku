#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5+10;
 
vector<int> adj[NMAX];
int subordinates[NMAX];
 
void dfs(int node) {
	subordinates[node] = 1;
	for (int next : adj[node]) {
		dfs(next);
		subordinates[node] += subordinates[next];
	}
}
 
int main() {
	int N;
	cin >> N;
	for (int i = 2; i <=N; i++) {
		int parent;
		cin >> parent;
		adj[parent].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		cout << subordinates[i] - 1 << " ";
	}
}
