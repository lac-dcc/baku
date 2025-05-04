#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	using ll = long long;
	ll n, m; cin >> n >> m;
	vector<pair<ll, ll>> adj[n + 1];
	for(ll i = 0; i < m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	vector<ll> maxDistances(n + 1, 1e15);
	maxDistances[1] = 0;
	pq.push({0, 1});
	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));
	while(!pq.empty()) {
		ll distance = pq.top().first;
		ll currentNode = pq.top().second;
		pq.pop();
		if(vis[currentNode]) {
			continue;
		}
		vis[currentNode] = 1;
		for(pair<ll, ll> x : adj[currentNode]) {
			ll node = x.first;
			ll cost = x.second;
			if(maxDistances[node] > distance + cost) {
				maxDistances[node] = distance + cost;
				pq.push({maxDistances[node], node});
			}
		}
	}
	for(ll i = 1; i <= n; i++) cout << maxDistances[i] << " \n"[i == n];
	return 0;
}
