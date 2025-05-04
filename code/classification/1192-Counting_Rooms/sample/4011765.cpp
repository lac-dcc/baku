#include <bits/stdc++.h>
using namespace std ;
#define LL long long
 
int n , m ;
vector<string> grid ;
vector<vector<bool>> vis ;
 
void dfs ( int r , int c ) {
    if ( r < 0 || r >= n )  return ;
    if ( c < 0 || c >= m )  return ;
    if ( vis[r][c] || grid[r][c] == '#' )    return ;
    vis[r][c] = 1 ;
    dfs(r, c + 1) ; dfs(r, c - 1) ; dfs(r + 1, c) ; dfs(r - 1, c) ;
}
 
int main()  {
    std::ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    cin >> n >> m ;
    grid = vector<string>(n) ;
    for ( auto & s : grid ) cin >> s ;
    
    vis = vector<vector<bool>>(n, vector<bool>(m, 0)) ;
    
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
        for ( int j = 0 ;j < m ; j ++ ) {
            if ( vis[i][j] || grid[i][j] == '#' )    continue ;
            cnt ++ ;
            dfs(i, j) ;
        }
    
    cout << cnt << endl ;
}
