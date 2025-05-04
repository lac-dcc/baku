#include <bits/stdc++.h>
using namespace std;
#define int long long
const int num = 1e14;
 
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> par;
 
void solve()
{
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    dist.clear();
    dist.resize(n + 1, num);
    par.clear();
    par.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
    }
 
    dist[1] = 0;
    int f;
    for (int i = 0; i < n; i++)
    {
        f = 0;
        for (int u = 1; u <= n; u++)
        {
            for (auto curr : g[u])
            {
                int v = curr.first;
                int d = curr.second;
 
                if (dist[v] > dist[u] + d)
                {
                    dist[v] = dist[u] + d;
                    par[v] = u;
                    f = v;
                }
            }
        }
    }
 
    if (!f)
    {
        cout << "NO\n";
        return;
    }
 
    cout << "YES\n";
    vector<int> cycle;
    for (int i = 1; i <= n; i++)
    {
        f = par[f];
    }
    for (int x = f;; x = par[x])
    {
        cycle.push_back(x);
        if (x == f && cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());
 
    for (auto v : cycle)
        cout << v << " ";
    cout << '\n';
}
 
signed main()
{
    solve();
    return 0;
}
