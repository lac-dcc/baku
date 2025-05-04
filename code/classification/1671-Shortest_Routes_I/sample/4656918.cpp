#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define ppb() pop_back()
#define ff first
#define ss second
const int MAXN = 1e5 + 5;
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
vector<pii> adj[MAXN];
ll dist[MAXN];
bool visited[MAXN];
int n, m;
 
void solve() {
	for (int i = 0; i <= n; ++i)
		dist[i] = LLONG_MAX;
 
	priority_queue<pair<ll, int>> q;
	q.push(mp(0, 1));
	dist[1] = 0;
 
	while (!q.empty()) {
		pair<ll, int> nd = q.top(); q.pop();
		nd.ff *= -1;
 
		if (visited[nd.ss]) continue;
		visited[nd.ss] = true;
 
		for (pii to : adj[nd.ss]) {
			if (dist[to.ff] > nd.ff + to.ss) {
				dist[to.ff] = nd.ff + to.ss;
				q.push(mp(-dist[to.ff], to.ff));
			}
		}
	}
}
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
 
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].pb(mp(b, c));
	}
 
	solve();
 
	for (int i = 1; i <= n; ++i)
		printf("%lld ", dist[i]);
	puts("");
	
	return 0;
}
