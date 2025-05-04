/// Kiertomatka: https://cses.fi/dt/task/390
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <LL> VL;
typedef vector <VL> VVL;
typedef vector <bool> VB;
 
bool dfs(const VVL &adj, LL u, LL k, LL level, VB &vis, VL &l, VL &path)
{
    l[u] = level;
    vis[u] = true;
    path.push_back(u);
    for(auto x:adj[u])
    {
        if (!vis[x])
        {
            if (dfs(adj, x, k, level+1, vis, l, path))
                return true;
        }
        else
        {
            if (level - l[x] >= k)
            {
                path.push_back(x);
                LL h = level - l[x];
                if (LL(path.size()) > h + 2)
                {
//                    reverse(path.begin(), path.end());
                    copy(path.end() - h - 2, path.end(), path.begin());
                    path.resize(h+2);
                 }
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}
 
/// find a tour starts somewhere, goes through at least k nodes and comes back to the beginning, for Round Trip: https://cses.fi/problemset/task/1669, k = 2
bool solve(const VVL &adj, LL k, VL &path)
{
    LL u, n = adj.size()-1;
    VB vis(n+1);
    VL l(n+1);
 
    for(u = 1; u <= n; u++)
    {
        if (!vis[u])
        {
            // path.clear();
            if (dfs(adj, u, k, 0, vis, l, path))
                return true;
        }
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL n, m, u, v, k = 2;   // k = 2 for https://cses.fi/problemset/task/1669
    cin >> n >> m;
    VVL adj(n+1);
    VL path;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    if (!solve(adj, k, path))
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << path.size() << "\n";
        for(auto x:path)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
