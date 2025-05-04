#include<bits/stdc++.h>
#define MAX 1020
#define mp make_pair
#define pb push_back
using namespace std;
 
char _floor[MAX][MAX];
int cont, pos[4] = {-1, 1, 0, 0};
vector<pair<int, int>> rooms;
 
void dfs(int x, int y){
    _floor[x][y] = '#';
 
    for(int i = 0, j = 3; i < 4; i++, j--){
        int nx = x + pos[i], ny = y + pos[j];
 
        if(_floor[nx][ny] == '.')
            dfs(nx, ny);
    }
}
 
int main(){
    int n, m;
    cin >> n >> m;
 
    memset(_floor, '#', sizeof _floor);
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> _floor[i][j];
 
            if(_floor[i][j] == '.'){
                rooms.pb(mp(i, j));
            }
        }
    }
 
    for(int i = 0; i < rooms.size(); i++){
        int a = rooms[i].first;
        int b = rooms[i].second;
 
        if(_floor[a][b] != '#'){
            dfs(a, b);
            cont++;
        }
    }
 
    cout << cont << endl;
 
    return 0;
}
