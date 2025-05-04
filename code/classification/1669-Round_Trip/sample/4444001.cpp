#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define mod 1000000007
#define f(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define endl '\n'
#define spc ' '
#define sz(a) (int)a.size()
#define sq(a) (a) * (a)
#define int long long
#define all(a) a.begin(), a.end()
 
typedef tree<pair<int, int>, null_type,
        less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
 
vector<int> ans;
bool b = false;
 
void dfs(vector<vi> &g, int node, int par, vector<int> &vis, int d) {
    vis[node] = d;
    for (auto x : g[node]) {
        if (x == par) continue;
        if (!ans.empty()) return;
        if (vis[x] == -1) dfs(g, x, node, vis, d);
        else if (vis[x] == d) {
            ans.pb(x);
            b = true;
        }
        if (b) {
            ans.pb(node);
            if (node == ans[0]) b = false;
        }
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vi> g(n);
    f(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) dfs(g, i, -1, vis, i);
    }
    if (ans.empty()) cout << "IMPOSSIBLE" << endl;
    else {
        cout << sz(ans) << endl;
        for (auto x : ans) cout << x + 1 << spc;
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
