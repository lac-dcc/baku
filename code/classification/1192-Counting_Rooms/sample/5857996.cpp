#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MAX = 1e3+5;
 
char g[MAX][MAX];
int n, m;
 
bool dfs(int i, int j) {
    if(g[i][j] != '.') {
        return false;
    }
    g[i][j] = '#';
    if(i+1 <= n) {
        dfs(i+1, j);
    }
    if(i-1 > 0) {
        dfs(i-1, j);
    }
    if(j+1 <= m) {
        dfs(i, j+1);
    }
    if(j-1 > 0) {
        dfs(i, j-1);
    }
 
    return true;
}
 
int32_t main(){
 
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            ans += dfs(i, j);
        }
    }
    cout << ans << '\n';
 
    return 0;
}
