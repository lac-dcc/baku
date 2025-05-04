#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
const int INF = 1e9 + 7;
const int nmax = 1e5 + 7;
 
int dist[nmax], trace[nmax];
bool f[nmax];
 
vector <int> a[nmax];
 
queue <int> q;
 
void bfs(int u)
{
    q.emplace(u);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
 
        for (auto it : a[u])
        {
            if (dist[it] > dist[u] + 1)
            {
                dist[it] = dist[u] + 1;
                trace[it] = u;
                if (!f[it]) q.emplace(it);
            }
        }
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
 
    for (int i = 2; i <= n; i++) f[i] = false, dist[i] = INF;
 
    dist[1] = 1;
 
    bfs(1);
    trace[1] = -1;
    if (dist[n] == INF) cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n] << "\n";
 
        vector <int> v;
        for ( ; n != -1; n = trace[n]) v.pb(n);
        reverse(v.begin(), v.end());
 
        for (auto it : v) cout << it << " ";
    }
 
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    #define task "CSES"
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
 
    int t = 1;
    if (!t) cin >> t;
    while (t--)
    {
        solve();
    }
 
    return 0;
}
