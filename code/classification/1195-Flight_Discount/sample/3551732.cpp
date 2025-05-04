#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
 
using ll = long long;
using plli = pair<ll,int>;
 
const int MAXN = 100100;
vector<pair<int,ll>> aa[2*MAXN];
int n, m;
priority_queue<plli, vector<plli>, greater<plli>> coda;
ll dist[2*MAXN];
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		aa[a].push_back({b, c});
		aa[a+n].push_back({b+n, c});
		aa[a].push_back({b+n, c/2});
	}
	for (int i = 1; i <= n; i++) aa[i].push_back({i+n, 0});
	for (int i = 1; i <= 2*n; i++) dist[i] = 1e18;
	coda.push({0, 1});
	while (!coda.empty()) {
		const auto [now, v] = coda.top();
		coda.pop();
		if (now > dist[v]) continue;
		for (const auto& [c, d]: aa[v]) if(now + d < dist[c]) {
			dist[c] = now + d;
			coda.push({now  + d, c});
		}
	}
	cout << dist[2*n];
}
