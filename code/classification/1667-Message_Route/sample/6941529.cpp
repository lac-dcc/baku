#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 4;
vector<int> adj[N];
bool visited[N];
int parent[N];
 
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    memset(visited, false, sizeof(visited));
    bfs(1);
 
    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        int current = n;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
 
        cout << path.size() << endl;
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
 
    return 0;
}
