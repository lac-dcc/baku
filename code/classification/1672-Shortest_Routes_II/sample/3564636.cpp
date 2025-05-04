#include "bits/stdc++.h"
using namespace std;
#define int long long
 
int n, e, qq;
vector<vector<int>> a;
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e >> qq;
    a.resize(n + 1, vector<int>(n + 1, 99999999999999999ll));
    for(int i = 1; i <= n; ++i) a[i][i] = 0;
    for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        a[x][y] = min(a[x][y], z);
        a[y][x] = min(a[y][x], z);
    }
    for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    }
    for(int i = 0, x, y; i < qq; ++i) {
        cin >> x >> y;
        cout << (a[x][y] == 99999999999999999ll ? -1 : a[x][y]) << "\n"; 
    }
}
