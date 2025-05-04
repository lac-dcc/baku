#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> ar[100001];
bool vis[100001];
int N , M;
 
int n, m, x, y; 
 
vector<int> adj[200005];
vector<int> ans(200005, -1);
 
int bfs(int src) {
	int top;
	queue<int> q;
	vector<int> d(n+1, -1);
	d[src] = 0;
	ans[src] = max(ans[src], d[src]);
	q.push(src);
 
	while(!q.empty()) {
		top = q.front();
		q.pop();
 
		for(int v: adj[top]) {
			if(d[v] == -1) {
				q.push(v);
				d[v] = d[top] + 1;
				ans[v] = max(ans[v], d[v]);
			}
		}
	}
	return top;
}
 
int main() {
	int u, v;
	
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int diam_end_1 = bfs(1);
	int diam_end_2 = bfs(diam_end_1);
	bfs(diam_end_2);
 
	for(int i = 1; i <=n ; i++) {
		cout << ans[i] << " ";
	}
}
