#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>> q;
vector<bool> visited;
vector<int> dist;
 
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
    file_i_o();
    int nodes, edges;
    cin >> nodes >> edges;
    adj.resize(nodes + 1);
    visited.resize(nodes + 1);
    dist.resize(nodes + 1, LONG_LONG_MAX);
    for (int i = 0; i < edges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
 
    dist[1] = 0;
 
    q.push({0, 1});
 
    while (!q.empty())
    {
        pair<int, int> root = q.top();
        q.pop();
        if (visited[root.second])
        {
            continue;
        }
        visited[root.second] = true;
        for (auto node : adj[root.second])
        {
            if (dist[node.first] > dist[root.second] + node.second)
            {
                dist[node.first] = dist[root.second] + node.second;
                q.push({-dist[node.first], node.first});
            }
        }
    }
 
    for (int i = 1; i <= nodes; i++)
    {
        cout << dist[i] << " ";
    }
 
    return 0;
}
