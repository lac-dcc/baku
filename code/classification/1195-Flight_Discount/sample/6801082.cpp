#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e18;
 
vector<int> dijkstra(int n, vector<vector<int>> adj[], int src)
{
    set<pair<int, int>> s;
    s.insert({0, src});
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
 
    while (!s.empty())
    {
        auto it = *(s.begin());
        int node = it.second;
        int dis = it.first;
        s.erase(it);
 
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
 
            if (dis + edW < dist[adjNode])
            {
                if (dist[adjNode] != INF)
                    s.erase({dist[adjNode], adjNode});
 
                dist[adjNode] = dis + edW;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
 
    return dist;
}
 
int32_t main()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> flights(m, vector<int>(3));
    vector<vector<int>> adj1[n + 1];
    vector<vector<int>> adj2[n + 1];
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        flights[i][0] = a;
        flights[i][1] = b;
        flights[i][2] = c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
 
    vector<int> dist1 = dijkstra(n, adj1, 1);
    vector<int> dist2 = dijkstra(n, adj2, n);
 
    int ans = INF;
    for (vector<int> edge : flights)
    {
        ans = min(ans, dist1[edge[0]] + dist2[edge[1]] + edge[2] / 2);
    }
    cout << ans << endl;
    return 0;
}
