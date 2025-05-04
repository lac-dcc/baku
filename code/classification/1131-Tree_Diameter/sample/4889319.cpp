#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 2e5;
int n, d[mxN], ans;
vector<int> adj[mxN];
/*
Base case is height of leaf nodes should be 0. 
*/
void dfs(int u = 0, int p = -1) {
    for(int v : adj[u]) {
        if(v == p) {
            continue;
        }
        dfs(v, u);
        ans = max(ans, d[u] + d[v] + 1);
        d[u] = max(d[u], d[v] + 1);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p, q;
        cin >> p >> q, --p, --q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    dfs();
    cout << ans << endl;
}
