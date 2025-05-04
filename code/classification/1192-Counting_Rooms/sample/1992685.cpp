#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 2;
 
int n, m;
char a[N][N];
bool vis[N][N];
 
int dx[] = {-1,1, 0,0};
int dy[] = {0,0 , -1,1};
 
void bfs(int i , int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = true;
 
    while ( q.size() ){
        auto node = q.front(); q.pop();
        for ( int k = 0; k < 4; ++k ){
            int x = node.first + dx[k];
            int y = node.second + dy[k];
 
            if ( x >= 0 and y >= 0 and x < n and y < m and a[x][y] != '#' and vis[x][y] == false ){
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}
 
int main(){
#ifdef CLion
    freopen("input.txt" , "r" , stdin);
#endif
 
    cin >> n >> m;
    for ( int i = 0; i < n; ++i ){
        for ( int j = 0; j < m; ++j ){
            cin >> a[i][j];
        }
    }
 
    int compSz = 0;
    for ( int i = 0; i < n; ++i ){
        for ( int j = 0; j < m; ++j ){
            if ( a[i][j] == '.' and vis[i][j] == false ){
                compSz++; bfs(i, j);
            }
        }
    }
 
    cout << compSz;
    return 0;
}
