#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
 
#define ll long long
 
using namespace std;
 
string graph[1010];
bool visited[1010][1010];
 
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
bool is_valid(int i, int j, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    if(graph[i][j] == '#') return false;
    else return true;
}
 
void dfs(int i, int j, int n, int m) {
    visited[i][j] = true;
    for(pair<int, int> dir : dirs) {
        int x = i + dir.first;
        int y = j + dir.second;
        if(is_valid(x, y, n, m) && visited[x][y] == false) {
            //cout<<"Doing DFS on "<<x<<" "<<y<<"\n";
            dfs(x, y, n, m);
        }
    }
}
 
int main()
{   
    memset(visited, false, sizeof visited);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>graph[i];
    }
    int rooms = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == '.' && visited[i][j] == false) {
                rooms++;
                dfs(i, j, n, m);
            }
        }
    }
 
    cout<<rooms;
    return 0;
}
