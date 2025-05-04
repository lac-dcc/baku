#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 2e5;
vector <int> g[mxN + 5], sub(mxN + 5);
 
void Dfs(int u , int par = -1) {
    sub[u] = 1;
    for (int v : g[u]) {
        if (v == par) continue;
        Dfs(v , u);
        sub[u] += sub[v];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n; cin >> n;
    for (int u = 2; u <= n; u++) {
        int v; cin >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    Dfs(1);
    for (int i = 1; i <= n; i++) cout << sub[i] - 1 << " ";
    return 0;
}
