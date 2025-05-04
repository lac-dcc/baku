#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
 
vector<vector<int>> g;
vector<bool> vis;
int sz = 1;
vector<int> ans;
void dfs(int v)
{
    vis[v] = true;
    for (int ch: g[v])
    {
        if (!vis[ch])
            dfs(ch);
    }
    if (ans.size() < sz) ans.emplace_back(v);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 1;
//    cin >> T;
    for (int x = 1; x <= T; ++x)
    {
        int n, m;
        cin >> n >> m;
        g.resize(n + 1);
        vis.resize(n + 1, false);
        for (int i = 0, u, v; i < m; ++i)
        {
            cin >> u >> v;
            g[v].emplace_back(u);
            g[u].emplace_back(v);
        }
        int c = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) {
                dfs(i);
                c++,sz++;
            }
        if (c > 1)
        {
            cout << c - 1 << '\n';
                for (int j = 1; j < (int) ans.size(); ++j)
                    cout << ans[0] << ' ' << ans[j] << '\n';
        }
        else cout << 0;
    }
}
