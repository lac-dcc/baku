#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
#define ll long long 
const int MAX_N = 100001;
 
vector<pair<int, int> > edges[MAX_N], edges2[MAX_N];
ll dist[MAX_N], dist2[MAX_N];
 
int main() {
    int n, m, x, y, z;
    scanf(" %d %d ", &n, &m);
    for (int i=0; i<m; i++) {
        scanf(" %d %d %d ", &x, &y, &z);
        edges[x].emplace_back(y, z);
        edges2[y].emplace_back(x, z);
    }
    
    for (int i=1; i<=n; i++) {
        dist[i] = 500000000000000000;
        dist2[i] = 500000000000000000;
    }
    
    dist[1] = 0;
    dist2[n] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		pair<ll, int> current = pq.top();
		pq.pop();
		if (current.first > dist[current.second]) continue;
		for (pair<int, int> next : edges[current.second]) {
			if (dist[next.first] > dist[current.second] + next.second) {
				dist[next.first] = dist[current.second] + next.second;
				pq.push(make_pair(dist[next.first], next.first));
			}
		}
	}
	
	pq.push(make_pair(0, n));
	while (!pq.empty()) {
		pair<ll, int> current = pq.top();
		pq.pop();
		if (current.first > dist2[current.second]) continue;
		for (pair<int, int> next : edges2[current.second]) {
			if (dist2[next.first] > dist2[current.second] + next.second) {
				dist2[next.first] = dist2[current.second] + next.second;
				pq.push(make_pair(dist2[next.first], next.first));
			}
		}
	}
    ll ans=1000000000000000000;
    for (int i=1; i<=n; i++) {
        for (pair<int, int> j : edges[i]) ans = min(ans, dist[i]+j.second/2+dist2[j.first]);
    }
    printf("%lld\n", ans);
}
