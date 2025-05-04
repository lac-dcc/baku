// Bipartite graph, duh!
#include <bits/stdc++.h>
using namespace std;
 
/* Similar to labryrinth, but we don't have bocked cells, instead we have separate components!
Also, we don't have a matrix maze, but a 1D one.*/
 
bool isBipartite(int node, vector<vector<int>> &adj, vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adjNode : adj[node])
        {
            if (color[adjNode] == color[node])
                return false;
            else if (color[adjNode] == -1)
            {
                color[adjNode] = 1 - color[node];
                q.push(adjNode);
            }
        }
    }
    return true;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    // use 0 for team 1 and 1 for team 2
    // Use BFS to color the graph
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(i, adj, color))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
 
    // Print the color of each node!
    for (int i = 1; i <= n; i++)
        cout << color[i] + 1 << " ";
    return 0;
}
