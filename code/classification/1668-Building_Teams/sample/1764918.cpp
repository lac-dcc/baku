/*
   author: rishi_mohan
   created_at: 27-02-2021  06:31 PM
*/
#include<bits/stdc++.h>
using namespace std;
 
#define    ll            long long
#define    all(x)        (x).begin(),(x).end()
 
vector<int> adj[200005];
vector<bool> vis(200005);
vector<int> col(200005);
 
bool good = 1;
void dfs(int nt, int c) {
    if (vis[nt]) return;
 
    vis[nt] = 1;
    col[nt] = c;
    for (auto j : adj[nt]) {
        if (!vis[j])
            dfs(j, c ^ 1);
        else {
            if (col[j] == c)
                good = 0;
        }
    }
}
 
void Solve() {
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, 0);
    }
    if (!good)
        cout << "IMPOSSIBLE" << '\n';
 
    else {
        for (int i = 1; i <= n; i++) {
            if (col[i] == 0)
                col[i] = 2;
 
            cout << col[i] << ' ';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  int t = 1;
    while (t--) Solve();
}
