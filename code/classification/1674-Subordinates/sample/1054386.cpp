#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
 
int n;
int subs[200013];
vector<int> g[200013];
 
int dfs(int u) {
    for (auto v : g[u])
        subs[u] += dfs(v);
 
    return subs[u] + 1;
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    cin >> n;
 
    for (int i = 2; i <= n; i++) {
        int c; cin >> c;
        g[c].push_back(i);
    }
 
    dfs(1);
 
    for (int i = 1; i <= n; i++)
        cout << subs[i] << " ";
}
