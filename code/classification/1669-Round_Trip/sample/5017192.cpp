#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> vis(100005);
vector<int> pa(100005);
int ans;
bool dfs (int u, int par)
{
    vis[u] = true;
    for (auto it : adj[u])
    {
        if (!vis[it])
        {
            pa[it] = u;
            if (dfs(it, u)) {return true;}
        }
        else
        {
            if (it != par) {ans = it;pa[it] = u;return true;}
        }
    }
    return false;
}
int main()
{
    int n, m; cin >>n >> m;
    for (int i = 0; i < m; i++)
    {
        int u,v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            ok = dfs(i, 0);
            if (ok == true) break;
        }
    }
    if (!ok) cout << "IMPOSSIBLE\n";
    else
    {
        int r = ans;
        vector<int> anss;
        anss.push_back(ans);
        ans = pa[ans];
        while (1)
        {
            anss.push_back(ans);
            ans = pa[ans];
            if (ans == r)
            {
                anss.push_back(r);
                break;
            }
        }
        cout << anss.size() << '\n';
        for (auto it : anss) cout << it << ' ';
 
    }
}
