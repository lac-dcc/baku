#include <bits/stdc++.h>
using namespace std;
char room[1001][1001];
int color[1001][1001], x,y;
int n, m, comp;
void dfs(int x, int y){
    color[x][y] = 1;
    if ( room[x-1][y] == '.' && color[x-1][y] == 0){
        dfs(x-1,y);
    }
    if (room[x+1][y] == '.' && color[x+1][y] == 0){
        dfs(x+1,y);
    }
    if (room[x][y-1] == '.' && color[x][y-1] == 0){
        dfs(x,y-1);
    }
    if (room[x][y+1] == '.' && color[x][y+1] == 0){
        dfs(x,y+1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>room[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(color[i][j] == 0 && room[i][j] == '.'){
                x = i;
                y = j;
                dfs(x,y);
                comp++;
            }
 
        }
    }
    cout<<comp;
 
}
