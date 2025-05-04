#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
char mat[1001][1001];
bool visited[1001][1001];
int posx[4] = {0, 1, -1, 0};
int posy[4] = {1, 0, 0, -1};
 
bool isValid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '#') {
        return true;    
    }
    
    return false;
}
 
void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int xx = x + posx[i];
        int yy = y + posy[i];
        
        if (isValid(xx, yy) && !visited[xx][yy]) {
            dfs(xx, yy);
        }
    }
}
 
int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
