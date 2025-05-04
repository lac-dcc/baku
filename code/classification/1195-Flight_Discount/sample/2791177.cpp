#include <bits/stdc++.h>
 
using namespace std;
 
#include <bits/stdc++.h>
 
using namespace std;
 
inline namespace // dijkstra
{
    template <typename C = int, bool _Directed = false>
    struct dijkstra
    {
        dijkstra(const int &_n) : n(_n), adj(n), dist(n) {}
 
        void add_edge(const int &u, const int &v, const C &wt)
        {
            adj[u].emplace_back(v, wt);
            if constexpr (!_Directed)
                adj[v].emplace_back(u, wt);
        }
 
        void gen(const int &src = 0)
        {
            fill(dist.begin(), dist.end(), array{numeric_limits<C>::max(), numeric_limits<C>::max()});
 
            {
                priority_queue<pair<C, int>> pq;
                for (pq.emplace(-(dist[src][0] = 0), src); !pq.empty();)
                {
                    auto node = pq.top();
                    pq.pop();
 
                    C wt = -node.first;
                    int u = node.second;
 
                    if (wt != dist[u][0])
                        continue;
 
                    for (const auto &[v, d] : get_adj(u))
                    {
                        if (dist[u][0] + d < dist[v][0])
                            pq.emplace(-(dist[v][0] = dist[u][0] + d), v);
                    }
                }
            }
            {
                priority_queue<pair<C, int>> pq;
                for (pq.emplace(-(dist[src][1] = 0), src); !pq.empty();)
                {
                    auto node = pq.top();
                    pq.pop();
 
                    C wt = -node.first;
                    int u = node.second;
 
                    if (wt != dist[u][1])
                        continue;
 
                    for (const auto &[v, d] : get_adj(u))
                    {
                        C cur = min(dist[u][1] + d, dist[u][0] + d / 2);
                        if (cur < dist[v][1])
                            pq.emplace(-(dist[v][1] = cur), v);
                    }
                }
            }
        }
 
        int size() const { return n; }
 
        C get_dist(const int &dest) const { return dist[dest][1]; }
 
        const vector<vector<pair<int, C>>> &get_adj() const { return adj; }
        const vector<pair<int, C>> &get_adj(const int &u) const { return adj[u]; }
 
    private:
        int n;
        vector<vector<pair<int, C>>> adj;
 
        vector<array<C, 2>> dist;
    };
 
} // namespace
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    dijkstra<long, true> graph(n);
    for (int j = 0; j < m; j++)
    {
        int a, b;
        long c;
        cin >> a >> b >> c;
 
        graph.add_edge(a - 1, b - 1, c);
    }
 
    graph.gen();
 
    cout << graph.get_dist(n - 1) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    solve();
 
    return 0;
}


