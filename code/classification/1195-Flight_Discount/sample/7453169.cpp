#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl '\n'
#define pb push_back
#define epsilon 1e-9
#define PI 3.141592653589793115997963468544185161590576171875
#define int long long
const int N = 1e5 + 10, inf = 1e14 + 10;
int n, m, ans = inf;
void dijikstra(int src, vector<int> &dist, vector<vector<pair<int, int>>> &adj)
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(dist[src], src);
    while (!pq.empty())
    {
        int dis = pq.top().first, node = pq.top().second;
        pq.pop();
        if (dist[node] <dis)
            continue;
 
        for (pair<int, int> v : adj[node])
        {
            int child = v.second;
            if (dist[node] + v.first < dist[child])
            {
                dist[child] = dist[node] + v.first;
                pq.emplace(dist[child], child);
            }
        }
    }
}
void test_case()
{
 
    cin >> n >> m;
    int edges[m][3];
    vector<int> dist1(n + 1, inf), dist2(n + 1, inf);
    vector<vector<pair<int, int>>> adj(n + 1), adj2(n + 1);
 
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i][0] = u, edges[i][1] = v, edges[i][2] = c;
        adj[u].emplace_back(c, v);
        adj2[v].emplace_back(c, u);
    }
    dijikstra(1, dist1, adj);
    dijikstra(n, dist2, adj2);
    int ans = inf;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], c = edges[i][2];
        ans = min(ans, dist1[u] + dist2[v] + c / 2);
    }
    cout << ans << '\n';
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        test_case();
    }
}
