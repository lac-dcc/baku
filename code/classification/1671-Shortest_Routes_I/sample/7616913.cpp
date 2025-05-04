#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
 
#define INF LLONG_MAX
 
vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int end)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> vis(n, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});
 
    while (!queue.empty())
    {
        int current_node = queue.top().second;
        queue.pop();
 
        if (vis[current_node])
            continue;
 
        vis[current_node] = true;
 
        for (auto edge : graph[current_node])
        {
            int adj_node = edge.first;
            int weight = edge.second;
 
            if (dist[current_node] + weight < dist[adj_node])
            {
                dist[adj_node] = dist[current_node] + weight;
                queue.push({dist[adj_node], adj_node});
            }
        }
    }
 
    return dist;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("saida.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        // graph[y].push_back({x,z});
    }
    vector<int> v = dijkstra(graph, 1, n);
    for (int i = 1; i <= n ; i++)
    {
        cout << v[i];
        (i == n) ? cout << endl : cout << " ";
    }
}


