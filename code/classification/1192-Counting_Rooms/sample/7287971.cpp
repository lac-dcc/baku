#include <bits/stdc++.h>
 
using namespace std;
 
#define fast        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll          long long
#define el          "\n"
#define pb          push_back
#define fi          first
#define se          second
#define all(v)      v.begin(), v.end()
#define fs(n)       fixed<<setprecision(n)
#define clz(x)      __builtin_clz(x)
#define popp(x)     __builtin_popcount(x)
#define ctz(x)      __builtin_ctz(x)
 
const int N = 1e6 + 6, mod = 1e9 + 7, OO = 0x3f3f3f3f;
int n, m ;
vector<vector<char>> adj;
vector<vector<bool>> vis;
bool isvalid(int i, int j) {
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;
    return true;
}
int dr[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j) {
    vis[i][j] = true;
    for (int d = 0; d < 4; ++d) {
        int nx = i + dr[d] , ny = j + dy[d];
        if ( isvalid(nx, ny) and !vis[nx][ny] and adj[i][j] == '.')
            dfs(nx, ny);
    }
}
 
int main() {
    fast;
    ll cnt = 0;
    cin >> n >> m;
    adj = vector<vector<char>>(n, vector<char>(m));
    vis = vector<vector<bool>> (n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] and adj[i][j] == '.') {
                dfs(i , j);
                cnt++;
            }
        }
    }
    cout << cnt << el;
}
