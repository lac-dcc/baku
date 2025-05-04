#include "bits/stdc++.h"
#define ll long long
#define ld long double
using namespace std;
int n, m;
char arr[1001][1001];
bool ok(int x, int y) {
    return x < n and y < m and x >= 0 and y >= 0 and arr[x][y] == '.';
}
void dfs(int i, int j, vector<vector<bool>> &vis) {
    vis[i][j] = true;
    if(ok(i+1, j) and !vis[i+1][j]) dfs(i+1, j, vis);
    if(ok(i-1, j) and !vis[i-1][j]) dfs(i-1, j, vis);
    if(ok(i, j+1) and !vis[i][j+1]) dfs(i, j+1, vis);
    if(ok(i, j-1) and !vis[i][j-1]) dfs(i, j-1, vis);
}
void solve() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) cin >> arr[i][j];
    }
    int cnt = 0;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(arr[i][j] == '.' and !vis[i][j]) {
                dfs(i, j, vis);
                ++cnt;
            }
        }
    }
    cout << cnt;
    
    
}
int main() {
    solve();
}
 
