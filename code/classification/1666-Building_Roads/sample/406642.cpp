#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
vector<vector<int>> g;
vector<bool> used;
 
void dfs(int v = 0) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) dfs(to);
    }
    return;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    g.resize(n);
    used.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans.push_back(make_pair(1, i + 1));
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans) cout << el.first << " " << el.second << endl;
    return 0;
}
