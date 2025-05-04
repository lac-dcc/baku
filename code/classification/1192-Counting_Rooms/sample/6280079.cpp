#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
 
int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
 
bool ok(int i, int j, vector<string>& grid) {
    return i >= 0 && i < grid.size() &&
           j >= 0 && j < grid[0].size() &&
           grid[i][j] == '.';
}
 
void dfs(int i, int j, vector<string>& grid) {
    grid[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        int r = i + di[k];
        int c = j + dj[k];
        if (ok(r, c, grid)) dfs(r, c, grid);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            ans++;
            dfs(i, j, grid);
        }
    }
    cout << ans << endl;
}
 
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
