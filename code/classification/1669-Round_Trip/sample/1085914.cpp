#include <bits/stdc++.h>
 
using namespace std;
 
bool dfs(int n, const vector<vector<int>>& g, int u, int p_u,
    vector<bool>& visited, vector<int>& parents)
{
    visited[u] = true;
    parents[u] = p_u;
 
    for (auto v : g[u])
        if (!visited[v]) {
            if (dfs(n, g, v, u, visited, parents))
                return true;
        } else {
            if (v != p_u) {
                vector<int> path;
 
                path.push_back(v + 1);
                while (u != v) {
                    path.push_back(u + 1);
                    u = parents[u];
                }
                path.push_back(v + 1);
 
                cout << path.size() << '\n';
                copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
                return true;
            }
        }
 
    return false;
}
 
void solve(int n, const vector<vector<int>>& g)
{
    vector<bool> visited(n, false);
    vector<int> parents(n, -1);
 
    for (auto i = 0; i < n; ++i)
        if (!visited[i])
            if (dfs(n, g, i, -1, visited, parents))
                return;
 
    cout << "IMPOSSIBLE\n";
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
    for (auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    solve(n, g);
 
    return 0;
}
 


