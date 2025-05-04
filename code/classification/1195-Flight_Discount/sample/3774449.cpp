#include <bits/stdc++.h>
 
#define endl "\n"
#define int long long int
 
using namespace std;
 
const int INF = 9e17;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> disc;
 
void dij()
{
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;
    for (int i = 2; i <= n; ++i)
    {
        dist[i] = INF;
        disc[i] = INF;
    }
    pq.push({0, {1, 0}});
 
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second.first;
        int f = pq.top().second.second;
        pq.pop();
 
        if (f == 1)
        {
            if (disc[u] < d)
                continue;
        }
 
        if (f == 0)
        {
            if (dist[u] < d)
                continue;
        }
 
        for (auto e : g[u])
        {
            int v = e.first, c = e.second;
            if (f == 0)
            {
                if (dist[v] > c + d)
                {
                    dist[v] = c + d;
                    pq.push({dist[v], {v, 0}});
                }
                if (disc[v] > d + c / 2)
                {
                    disc[v] = d + c / 2;
                    pq.push({disc[v], {v, 1}});
                }
            }
 
            if (f == 1)
            {
                if (disc[v] > d + c)
                {
                    disc[v] = d + c;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
 
    cout << disc[n] << endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1);
    disc.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
 
    dij();
}
