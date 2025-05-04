#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5, MOD = 1e9 + 7;
 
int n, m, ans;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
vector<vector<char>> building;
 
void dfs(int r, int c) {
    if (r < 1 || c < 1 || r > n || c > m || building[r][c] == '#') return;
    building[r][c] = '#';
    for (int d = 0; d < 4; d++)
        dfs(r + dr[d], c + dc[d]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n >> m;
    building = vector<vector<char>>(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> building[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (building[i][j] != '.') continue;
            dfs(i, j);
            ans++;
        }
    cout << ans;
}
