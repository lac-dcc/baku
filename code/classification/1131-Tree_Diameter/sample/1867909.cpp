#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
 
int n;
vector<int> G[MAXN];
int h[MAXN], d[MAXN];
 
void init() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
 
void dfs(int u, int par) {
    h[u] = 0;
    int a = 0, b = 0;
    for (int v : G[u]) {
        if (v != par) {
            dfs(v, u);
            if (h[v] + 1 >= a) {
                b = a;
                a = h[v] + 1;
            } else if (h[v] + 1 >= b) {
                b = h[v] + 1;
            }
        }
    }
    h[u] = a;
    d[u] = a + b;
}
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    init();
    dfs(1, 0);
    int ans = *max_element(d + 1, d + 1 + n);
    cout << ans << '\n';
    return 0;
}
