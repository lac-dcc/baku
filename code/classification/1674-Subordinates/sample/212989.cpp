#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
 
const int N = 2e5 + 10;
vector<vector<int>> g(N);
vector<int> ans(N, 0);
 
int dfs(int v) {
    ans[v] = 1;
    for (auto &u : g[v]) {
        ans[v] += dfs(u);
    }
    return ans[v];
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        g[parent].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << " ";
    }
    cout << "\n";
}
