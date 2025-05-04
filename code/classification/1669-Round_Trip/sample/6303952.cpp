#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
int n, m;
const int N = 1e5 + 5;
vector<int> g[N];
int vis[N], par[N];
int cs = -1, ce = -1;
 
bool dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            par[v] = u;
            if (dfs(v)) return true;
        } else if (v != par[u]) {
            cs = v;
            ce = u;
            return true;
        }
    }
    return false;
}
 
signed main() {
    fast_io;
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i)) break;
 
    if (cs == -1)
        cout << "IMPOSSIBLE\n";
    else {
        vector<int> path;
 
        int cur = ce;
        while (cur != cs) {
            path.push_back(cur);
            cur = par[cur];
        }
        path.push_back(cs);
        reverse(path.begin(), path.end());
        path.push_back(cs);
 
        cout << path.size() << "\n";
        for (int x : path) cout << x << " ";
    }
 
    return 0;
}
