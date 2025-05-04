#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <climits>
#include <limits>
#include <math.h>
using namespace std;
 
long long n, m;
bool vis[1000][1000];
void dfs(int i, int j){
    deque<pair<int,int>> q;
    q.push_front({i,j});
    pair<int,int> act;
    vis[i][j] = 1;
    int row, col;
    
    while(!q.empty()){
        act = q.front();
        q.pop_front();
        row = act.first;
        col = act.second;
        row++;
        if(row < n && !vis[row][col]) {
            q.push_front({row, col});
            vis[row][col] = 1;
        }
        row -= 2;
        if(row >= 0 && !vis[row][col]) {
            q.push_front({row, col});
            vis[row][col] = 1;
        }
        row++;
        col++;
        if(col < m && !vis[row][col]) {
            q.push_front({row, col});
            vis[row][col] = 1;
        }
        col -= 2;
        if(col >= 0 && !vis[row][col]) {
            q.push_front({row, col});
            vis[row][col] = 1;
        }
    }
}
int t;
string s;
void solve(){
    cin >>n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            vis[i][j] = (s[j] == '#');
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]) {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt <<"\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
 
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    return 0;
}
