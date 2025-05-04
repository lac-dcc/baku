#include <bits/stdc++.h>
#define ll long long
#define gap " "
#define pii pair<ll,ll>
using namespace std;
const ll  mod = 998244353;
const ll  N = 1e5 + 10;
vector<int>g[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool is_bip = true;
    vector<int>side(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (side[i] != -1) continue;
        queue<int>q;
        q.push(i);
        side[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (side[v] == -1) {
                    side[v] = (1 ^ side[u]);
                    q.push(v);
                }
                else is_bip &= (side[v] != side[u]);
            }
        }
    }
    if (!is_bip)  return cout << "IMPOSSIBLE", 0;
    for (int i = 1; i <= n; ++i) cout << 1 + side[i] << " ";
}
