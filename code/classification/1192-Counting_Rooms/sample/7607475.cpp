#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define ll long long int
#define pii pair<int, int>
#define endl "\n"
using namespace std;
int total = 0;
int n, m;
void dfs(int i, int j, vector<vector<char>> &box) {
    if (i < 0 || j < 0 || i >= n || j >= m || box[i][j] != '.') {
        return;
    }
    box[i][j] = '#';
    dfs(i + 1, j, box);
    dfs(i, j + 1, box);
    dfs(i - 1, j, box);
    dfs(i, j - 1, box);
}
signed main() {
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    vector<vector<char>> box(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == '.') {
                total++;
                dfs(i, j, box);
            }
        }
    }
    cout << total << '\n';
 
    system("pause");
    return 0;
}
/*/
5 8
########
#..#...#
####.#.#
#..#...#
########
/*/
