#include <bits/stdc++.h>
using ll = long long ;
using namespace std;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
 
#define all(v) v.begin(),v.end()
 
char a[1005][1005] ;
int vis[1005][1005] ;
 
int dx[] = {1 , -1 , 0 ,  0} ;
int dy[] = {0 ,  0 , 1 , -1} ;
 
int ans = 0 ;
int n , m ;
 
bool valid ( int r , int c ) { return r >= 0 && r < n && c >= 0 && c < m ; }
 
void dfs ( int i , int j ) {
 
 if ( a[i][j] == '#' || vis[i][j] == 1 || !valid(i,j) ) return ;
 
 vis[i][j] = 1 ;
 
 for ( int k = 0 ; k < 4 ; k++) {
    int newi = dx[k] + i ;
    int newj = dy[k] + j ;
    dfs( newi , newj ) ;
 }
 
}
 
int main()
{
 
cin >> n >> m ;
for ( int i = 0  ; i < n ; i++ ) {
    for ( int j =  0 ; j < m ; j++) {
        cin >> a[i][j] ;
    }
}
int ans = 0 ;
memset(vis,0,sizeof(vis)) ;
for ( int i = 0  ; i < n ; i++ ) {
    for ( int j = 0 ; j < m ; j++) {
        if ( !vis[i][j] && a[i][j] == '.' ) {
            ans++;
            dfs(i,j) ;
        }
    }
}
cout << ans << endl ;
}
