#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
const ll INF = 2e18 + 7;
 
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> gr(n + 1), grt(n + 1);
    vector<tuple<int, int, int>> edgs;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        gr[a].push_back({b, c});
        grt[b].push_back({a, c});
        edgs.push_back({a, b, c});
    }
    vector<ll> dst(n + 1, INF), rdst(n + 1, INF);
    auto dijkstra = [](auto &dst, auto &gr, int s) {
        dst[s] = 0;
        set<pair<ll, int>> st{{0, s}};
        while (!st.empty()) {
            int cur = st.begin()->second;
            st.erase(st.begin());
            for (auto[v, w]: gr[cur]) {
                if (dst[cur] + w < dst[v]) {
                    st.erase({dst[v], v});
                    dst[v] = dst[cur] + w;
                    st.insert({dst[v], v});
                }
            }
        }
    };
    dijkstra(dst, gr, 1);
    dijkstra(rdst, grt, n);
    ll ans = INF;
    for (auto[u, v, w]: edgs) {
        if (dst[u] == INF || rdst[v] == INF) continue;
        ans = min(ans, dst[u] + w / 2 + rdst[v]);
    }
    cout << ans;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
