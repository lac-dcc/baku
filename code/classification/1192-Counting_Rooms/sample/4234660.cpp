#include <bits/stdc++.h>
 
using namespace std;
 
bool isvalid(int i,  int j, int m, int n, vector<vector<char>> &grid){
      if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='#'){
        return false;
      }
      return true;
}
 
void dfs(int i, int j, int m, int n, vector<vector<char>> &grid){
      grid[i][j]= '#';
      if(isvalid(i+1,j, m, n, grid) and grid[i+1][j]=='.'){
         dfs(i+1, j, m,n, grid);
      }
 
      if(isvalid(i,j+1, m, n, grid) and grid[i][j+1]=='.'){
         dfs(i, j+1, m,n, grid);
      }
 
      if(isvalid(i-1,j, m, n, grid) and grid[i-1][j]=='.'){
         dfs(i-1, j, m,n, grid);
      }
 
      if(isvalid(i,j-1, m, n, grid) and grid[i][j-1]=='.'){
         dfs(i, j-1, m,n, grid);
      }
 
}
 
int main(){
  int n;
  int m;
  cin>>n;
  cin>>m;
  vector<vector<char>> grid(n, vector<char>(m));
 
  for(int i=0; i<n; i++){
     for(int j=0; j<m; j++){
        cin>>grid[i][j];
     }
  }
int count=0;
 
 
for(int i=0; i<n; i++){
    for(int j=0;j<m; j++){
        if(grid[i][j]=='.'){
                count++;
                dfs(i, j, m, n, grid);
        }
    }
}
cout<<count<<endl;
 
}
