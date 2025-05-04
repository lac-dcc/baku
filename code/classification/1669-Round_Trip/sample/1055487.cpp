#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
 
#define taskname ""
#define lli long long
#define fi first
#define se second
 
const int N = 1e5 + 5;
const int MAX = 1e6 + 5;
const lli INF = 1e14;
const int MOD = 1e9 + 7;
 
int n, m, u, v;
bool Vis[N];
int vis[N], nxt[N];
vector<int> g[N];
vector<int> ans;
 
bool dfs(int u, int p)
{
    if (!vis[u]) {
        vis[u] = 1;
        Vis[u] = 1;
        for (int i : g[u]) {
            if (!vis[i] && dfs(i, u) && i != p) {
                nxt[u] = i;
                return 1;
            }
            else {
                if (Vis[i] && i != p) {
                    nxt[u] = i;
                    return 1;
                }
            }
        }
    }
 
    Vis[u] = 0;
    return 0;
}
 
int main()
{
    //freopen(taskname".inp", "r", stdin);
    //freopen(taskname".out", "w", stdout);
 
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++ i) {
        if (!vis[i]) {
            ans.clear();
            if (dfs(i, 0)) {
                u = i;
                for (int i = 0; i <= n; ++ i) {
                    vis[i] = 0;
                }
                while (vis[u] == 0) {
                    vis[u] = ans.size();
                    ans.push_back(u);
                    u = nxt[u];
                }
 
                cout << ans.size() - vis[u] + 1 << "\n";
                for (int i = vis[u]; i < ans.size(); ++ i) {
                    cout << ans[i] << " ";
                }
                cout << u;
                /*vis[ans.back()] = 0;
                for (int i = 0; i < ans.size(); ++ i) {
                    //cout << i << " ";
                    if (vis[ans[i]] >= 0) {
                        v = i + 1;
                        break;
                    }
                    vis[ans[i]] = i + 1;
                }
 
                cout << v - vis[ans[v - 1]] + 1 << "\n";
                for (int i = vis[ans[v - 1]]; i <= v; ++ i) {
                    if (i == 0) {
                        cout << ans.back() << " ";
                    }
                    else {
                        cout << ans[i - 1] << " ";
                    }
                }*/
                return 0;
            }
        }
    }
 
    cout << "IMPOSSIBLE";
    return 0;
}
