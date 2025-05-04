#include <bits/stdc++.h>
	
using namespace std;
 
int n, m;
void dijkstra(int start, vector<vector<pair<int,int>>> &adj, vector<long long> &dist){
	dist[start] = 0;
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	pq.push({0, start});
	while(pq.size()){
		auto [len, u] = pq.top();
		pq.pop();
		if (len != dist[u]) continue;
		for (auto [v, w] : adj[u]){
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}
 
void solve(){
	cin >> n >> m;
	vector<vector<pair<int,int>>> G(n + 1), revG(n + 1);
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v ,w});
		revG[v].push_back({u, w});
	}
	vector<long long> dist1(n + 1, 1e15), distN(n + 1, 1e15);
	dijkstra(1, G, dist1); dijkstra(n, revG, distN);
	long long ans = 1e15;
	for (int u = 1; u <= n; u++){
		for (auto [v, w] : G[u]){
	//		if (dist1[u] == 1e15 || distN[v] == 1e15) continue;
			ans = min(ans, dist1[u] + w/2 + distN[v]);
		}
	}
	cout << ans;
}
 
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
//	freopen("fencedin.in", "r", stdin);
//	freopen("fencedin.out", "w", stdout);
	int t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}