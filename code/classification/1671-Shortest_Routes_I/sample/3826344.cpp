#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;
 
void dijikstra(int src, vector<vector<pair<int, int>>> &g, vector<int> &dist, int n)
{
    dist[src] = 0;
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    while (q.size() > 0)
    {
        pair<int, int> t = q.top();
        q.pop();
 
        int curr = t.second;
        if (vis[curr])
            continue;
        vis[curr] = 1;
        for (auto ne : g[curr])
        {
            int child = ne.first;
            int wt = ne.second;
            if (dist[child] > wt + dist[curr])
            {
                dist[child] = wt + dist[curr];
                q.push({-1 * dist[child], child});
            }
        }
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        int wt;
        cin >> u;
        cin >> v;
        cin >> wt;
        g[u].push_back({v, wt});
    }
    vector<int> dist(n + 1, LLONG_MAX);
    dijikstra(1, g, dist, n);
 
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}
