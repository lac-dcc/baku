#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
char grid[1010][1010];
bool vis[1010][1010];
 
int movx[4] = {1, -1, 0, 0};
int movy[4] = {0, 0, 1, -1};
 
int n, m;
bool is_valid(int x, int y){
    if(grid[x][y] == '#' or vis[x][y] or x<1 or x>n or y<1 or y>m) return false;
    return true;
}
 
void cover(int x, int y){
    vis[x][y] = true;
    for(int i=0; i<4; i++){
        if(is_valid(x+movx[i], y+movy[i])){
            cover(x+movx[i], y+movy[i]);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> grid[i][j];
        }
    }
 
    int ans = 0; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j] == '.' and !vis[i][j]){
                ans++;
                cover(i,j);
            }
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
