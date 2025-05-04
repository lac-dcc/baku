#include <bits/stdc++.h> 
#include <set> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> //pair
#include <string>
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define N 1000
typedef long long ll;
using namespace std;
 
int grid[N][N];
bool visited[N][N];
int cnt = 0;
 
void floodFillNonRecursive(int i, int j, int src, int len_i, int len_j){
    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = true;
    if(src == -1){
        src = grid[i][j];
    }
 
    while(!q.empty()){
        auto& p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
 
        if(r+1 < len_i && !visited[r+1][c] && grid[r+1][c] == src){
            q.push({r+1, c});
            visited[r+1][c] = true;
        }
        if(r > 0 && !visited[r-1][c] && grid[r-1][c] == src){
            q.push({r-1, c});
            visited[r-1][c] = true;
        }
        if(c > 0 && !visited[r][c-1] && grid[r][c-1] == src){
            q.push({r, c-1});
            visited[r][c-1] = true;
        }
        if(c+1 < len_j && !visited[r][c+1] && grid[r][c+1] == src){
            q.push({r, c+1});
            visited[r][c+1] = true;
        }
    }
}
 
int main() { 
 
  int r, c;
  cin >> r >> c;
  string inputs[r];
  for(int i = 0; i<r; i++) cin >> inputs[i];
 
  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
        if(inputs[i][j] == '.')
            grid[i][j] = 1;
    }
  }
 
  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
        if(grid[i][j] == 1 && !visited[i][j]){
            floodFillNonRecursive(i, j, 1, r, c);
            cnt++;
        }
    }
  }
 
  cout << cnt << endl;
 
return 0;
}
