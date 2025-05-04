#pragma optimize("O2")
#include<bits/stdc++.h>
#define int long long int
#define S second
#define F first
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) cout << x, exit(0)
#define endl "\n"
 
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
 
const int MAXN = (int)3e5 + 23;
const int MOD = (int)1e9 + 7; //998244353;
const int INF = (int)1e18 + 7;
const int LG = 20;
 
 
int n, k, tmp, tmp2, tmp3, tmp4, m, u, v, w, q, p, l, r, ans;
int arr[MAXN], dist[MAXN], seen[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> Q;
 
 
 
 
 
int32_t main() {
	ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
 
	cin >> n >> m;
	
	for (int i=0; i<m; i++) {
		cin >> u >> v >> w;
 
		adj[u].pb({v, w});
	}
 
	fill(dist+2, dist+n+1, INF);
	Q.push({0, 1});
 
	while (!Q.empty()) {
		v = Q.top().S;
		Q.pop();
 
		if (seen[v]) continue;
		seen[v] = 1;
 
		for (auto cur:adj[v]) {
			u = cur.F;
 
			if (dist[u] > dist[v]+cur.S) {
				dist[u] = dist[v]+cur.S;
				Q.push({dist[u], u});
			}
		}
	}
 
	for (int i=1; i<=n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
 
 
 
	return 0;
}
 
