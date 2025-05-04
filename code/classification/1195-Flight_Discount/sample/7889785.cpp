#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MAXN = 2E5 + 16, INF = 1E18 + 16;
vector <pair <ll, ll> > adj[MAXN];
bool vis[MAXN];
vector <ll> dis(MAXN, INF);
 
int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
        adj[u + n].push_back({ v + n, w });
        adj[u].push_back({ v + n, w / 2 });
    }
    priority_queue <pair <ll, ll> > pq;
    pq.push({ 0, 0 });
    dis[0] = 0;
    while (!pq.empty()) {
        ll id = pq.top().second; pq.pop();
        if (vis[id]) continue;
        vis[id] = true;
        for (auto child : adj[id]) {
            if (dis[child.first] <= dis[id] + child.second) continue;
            dis[child.first] = dis[id] + child.second;
            pq.push({ -dis[child.first], child.first });
        }
    }
    cout << dis[2 * n - 1] << '\n';
    return 0;
}
