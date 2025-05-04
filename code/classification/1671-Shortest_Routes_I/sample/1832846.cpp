#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;
 
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
 
template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
 
vector<pii> adj[100001];
priority_queue<plli, vector<plli>, greater<plli>> pq;
ll dist[100001];
 
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
	}
 
	memset(dist, INFL, sizeof(dist));
	pq.emplace(0, 1), dist[1] = 0;
	while (!pq.empty()) {
		ll cw = pq.top().first; int cv = pq.top().second; pq.pop();
		if (cw > dist[cv]) continue;
		for (auto i : adj[cv]) {
			ll d = cw + i.second;
			if (d < dist[i.first])
				dist[i.first] = d, pq.emplace(d, i.first);
		}
	}
 
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	cout << '\n';
	return 0;
}