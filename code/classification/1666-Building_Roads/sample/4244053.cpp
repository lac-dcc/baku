#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void dfs(int src, vector<int> adj[], bool vis[]) {
    vis[src] = true;
    for (int x : adj[src]) {
        if (!vis[x]) {
            dfs(x, adj, vis);
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }
    vector<int> rep;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            rep.push_back(i + 1);
        }
    }
    cout << rep.size() - 1 << '\n';
    for (int i = 1; i < rep.size(); i++) {
        cout << rep[i - 1] << ' ' << rep[i] << '\n';
    }
    return 0;
}
