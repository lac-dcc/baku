#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 0x3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
 
struct Edge {
	int v, w, net = 0;
} edg[maxn<<2];
int ecnt = 1, head[maxn];
 
inline void add_edge(int u, int v, int w) {
	edg[++ecnt] = {v, w, head[u]};
	head[u] = ecnt;
}
 
long long dis[maxn];
int pre[maxn], cnt[maxn];
bitset<maxn> inque, vis;
 
int spfa(int n) {
	queue<int> que;
	inque[n+1] = n+1;
	que.emplace(n+1);
	fill(dis, dis + maxn, INF);
	dis[n+1] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		inque[u] = 0;
		for (int i = head[u]; i; i = edg[i].net) {
			int v = edg[i].v;
			if (dis[u] + edg[i].w < dis[v]) {
				pre[v] = u;
				dis[v] = dis[u] + edg[i].w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > n) return v;
				if (!inque[v])
					inque[v] = 1, que.emplace(v);
			}
		}
	}
	return -1;
}
 
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		add_edge(n+1, i, 0);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	int t = spfa(n);
	if (t == -1) cout << "NO\n";
	else {
		cout << "YES\n";
		int p = t, ed;
		vector<int> ans;
		while (1) {
			ans.emplace_back(p);
			if (vis[p]) {
				ed = p; break;
			}
			else vis[p] = 1;
			p = pre[p];
		}
		reverse(ans.begin(), ans.end());
		while (ans.back() != ed) ans.pop_back();
		for (int v : ans) cout << v << ' ';
	}
}
 
signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0; 
}
