#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
 
vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);
vector<int> roads;
 
void dfs(int u) {
    visited[u] = true;
    for (auto& v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
 
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("./input.txt", "r", stdin);
 
 
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            roads.push_back(i);
            dfs(i);
        }
    }
 
    cout << roads.size() - 1 << '\n';
    for (int i = 0; i < roads.size() - 1; i++) {
        cout << roads[i] << ' ' << roads[i + 1] << '\n';
    }
 
 
    return 0;
}
