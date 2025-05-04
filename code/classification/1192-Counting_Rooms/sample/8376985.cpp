#include<bits/stdc++.h>
using namespace std;
int n,m,rooms = 0;
int neighbor_x[4] = {0,0,1,-1};
int neighbor_y[4] = {1,-1,0,0};
char building_map[1001][1001];
int visited [1001][1001];
bool check_cell(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    if(visited[x][y] == 1 || building_map[x][y] == '#'){
        return false;
    }
    return true;
}
 
void dfs(int x, int y){
    visited[x][y] = 1; // Mark the current cell as visited
 
    // Traverse the neighbors
    for (int i = 0; i < 4; i++) {
        int newX = x + neighbor_x[i];
        int newY = y + neighbor_y[i];
        
        if (check_cell(newX, newY)) { // Check if the neighbor is valid
            dfs(newX, newY); // Recursive call to explore the neighbor
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           cin>>building_map[i][j];
        }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (building_map[i][j] == '.' && !visited[i][j]) {
          dfs(i, j);
          rooms++;
        }
      }
    }
    cout<<rooms<<endl;
    return 0;
}
