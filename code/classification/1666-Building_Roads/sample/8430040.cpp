#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int n, m;
vector<int> adj_list[N];
int visited[N];
vector<int> roads;
 
void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
        if (!visited[adj_node])
            dfs(adj_node);
}
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            roads.push_back(i);
            dfs(i);
        }
    }
 
    cout << roads.size() - 1 << endl;
    for (int i = 0; i < roads.size() - 1; i++)
        cout << roads[i] << " " << roads[i + 1] << endl;
}
