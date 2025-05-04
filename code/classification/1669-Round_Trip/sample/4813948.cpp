#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
 
vector<vector<int>> g;
vector<int> d;
stack<int> s;
 
void dfs(int u, int prev) {
    s.push(u);
    for (int v : g[u]) {
        if (v == prev) continue;
        if (d[v] != -1) {
            cout << d[u] - d[v] + 2 << '\n' << v;
            while (1) {
                int c = s.top(); s.pop();
                cout << ' ' << c;
                if (c == v) exit(0);
            }
        }
        d[v] = d[u] + 1;
        dfs(v, u);
    }
    s.pop();
}
 
int main() {
    speed;
    int n, u, v;
    cin >> n >> u;
    g.resize(n + 1);
    d.resize(n + 1, -1);
    while (cin >> u >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] != -1) continue;
        d[i] = 0;
        dfs(i, -1);
    }
    cout << "IMPOSSIBLE";
}
