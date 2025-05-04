 /* In the name of God */
     
#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pii pair <long, long>
using namespace std;
const ll mod = 1e6;
const int N = 1e5 + 5;
int n, m;
vector<vector<int>> adj(N), cycle(N);
vector<int> p(N);
vector<bool> vis(N);
int c = 0;
// print any valid cycle, but.. how to find it
void dfs(int node, int par = 0) {
    p[node] = par;
    vis[node] = 1;
    for (int to : adj[node]) {
        if(to == par) {
            continue;
        }
        if(vis[to]) {
            vector<int> ans;
            int u = node;
            while(node ^ to) {
                ans.push_back(node);
                node = p[node];
            }
            ans.push_back(to);
            ans.push_back(u);
            cout << ans.size() << '\n';
            for (int a : ans) {
                cout << a << ' ';
            }
            exit(0);
        } else {
            dfs(to, node);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
int main()  {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        // cout << "Case #" << tc << ": ";
        solve();
    } 
}                               
