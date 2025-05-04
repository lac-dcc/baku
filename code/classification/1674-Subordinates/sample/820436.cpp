#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
 
int main()
{
    usaco();
    int n, x;
    cin >> n;
    vector <int> adj[n+1], vis(n+1), sub(n+1);
    for (int i = 2; i <= n; ++i)
    {
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    function <void(int, int)> dfs = [&](int u, int par)
    {
        vis[u] = 1;
        for (auto v : adj[u]) if (!vis[v]) dfs(v, u);
        if (par) sub[par] += sub[u]+1;
    };
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << sub[i] << " ";
}
