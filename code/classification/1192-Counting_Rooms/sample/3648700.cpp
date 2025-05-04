#include <bits/stdc++.h>
 
using namespace std;
 
char c;
int n,m, res;
int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
bool vis[1000][1000];
 
void dfs(int x, int y){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int dx = x+h[i], dy = y+v[i];
        if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy])
            dfs(dx, dy);
    }
}
 
int main(){
   cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           cin>>c;
            vis[i][j] = (c == '#');
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]){
                dfs(i, j);
                res++;
            }
        }
    }
   cout<<res;
   return 0;
}
