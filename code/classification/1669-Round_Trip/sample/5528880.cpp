#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (x).size()
 
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
#define endl "\n";
 
#define MOD 1e9 + 7
 
const int MAX_N = 1e5+1;
 
vi adj[MAX_N];
int vis[MAX_N];
vi ans;
int s;
bool dfs(int u, int p, int pre) {
    vis[u] = p;
    for (int v : adj[u]) {
        if (v == pre) {
            continue;
        }
        if (vis[v]) {
            if (vis[v] == p) {
                s = v;
                ans.pb(v);
                ans.pb(u);
                return 1;
            }
            continue;
        }
        if (dfs(v, p, u)) {
            ans.pb(u);
            if (s == u) {
                cout << sz(ans) << endl;
                for (int i : ans) {
                    cout << i <<  " ";
                }
                exit(0);
            }
            return 1;
        }
    }
    return 0;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans.clear();
            dfs(i, i, 0);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
