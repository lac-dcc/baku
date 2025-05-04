#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
 
const int maxn = 1e5 + 5;
vector<int> graph[maxn];
int visited[maxn], parent[maxn], color[maxn];
 
void dfs_c(int u, int p)
{
    parent[u] = p;
    visited[u] = 1;
    for (int v : graph[u])
    {
        if (visited[v] == 0)
        {
            dfs_c(v, u);
        }
        else if (v != p && visited[v] == 1)
        {
            vector<int> cycle = {v};
            while (u != v)
            {
                cycle.push_back(u);
                u = parent[u];
            }
            cycle.push_back(v);
 
            reverse(all(cycle));
 
            cout << cycle.size() << endl;
            for (int x : cycle)
                cout << x << " ";
 
            exit(0);
        }
    }
    visited[u] = 2;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    for (int u = 1; u <= n; u++)
        if (!visited[u])
            dfs_c(u, 0);
 
    cout << "IMPOSSIBLE";
}
