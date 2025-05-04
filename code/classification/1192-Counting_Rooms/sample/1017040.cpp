#include<bits/stdc++.h>
using namespace std;
 
const int mxN = 1e3, mxM = 1e3;
char grid[mxN][mxM];
vector<vector<bool>> visited(mxN, vector<bool>(mxM, false));
int n, m;
 
vector<array<int,2>> dir = {{1,0}, {0,1}, {-1,0}, {0, -1}};
 
bool isValid(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}
 
void dfs(int i, int j){
    visited[i][j] = true;
    for(auto pair : dir){
        int new_row = i+pair[0];
        int new_col = j+pair[1];
        if(isValid(new_row, new_col) && grid[new_row][new_col] == '.' && !visited[new_row][new_col]){
            dfs(new_row,new_col);
        }
    }
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;
}
