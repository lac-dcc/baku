#include <bits/stdc++.h>
 
using namespace std;
 
#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
 
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; v++) {
        int u;
        cin >> u;
        adj[u - 1].push_back(v);
    }
 
    vector<int> dp(n);
    auto dfs = [&](auto &&self, int u) -> void {
        for (auto v : adj[u]) {
            self(self, v);
            dp[u] += dp[v] + 1;
        }
    };
    dfs(dfs, 0);
 
    for (int u = 0; u < n; u++) {
        cout << dp[u] << " \n"[u == n - 1];
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}
