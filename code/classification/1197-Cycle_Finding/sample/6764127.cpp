#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    using ll = long long;
    vector<vector<ll>> edges(m, vector<ll>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int x = -1;
    const ll INF = 1e15;
    vector<ll> dis(n + 1);
    vector<int> p(n + 1, -1);
    dis[1] = 0;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            ll wt = e[2];
            if (dis[u] + wt < dis[v]) {
                dis[v] = dis[u] + wt;
                p[v] = u;
                x = v;
            }
        }
    }
    if (x == -1) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
        int y = x;
        for (int i = 0; i < n; i++) y = p[y];
        vector<int> cycle;
        for (int curr = y; ; curr = p[curr]) {
            cycle.push_back(curr);
            if (curr == y and (int) cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto &e : cycle) cout << e << " ";
        cout << "\n";
    }
    return 0;
}
