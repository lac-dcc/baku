#include <bits/stdc++.h>
using namespace std;
 
int n, m, roomCount = 0;
vector<vector<bool>> visited;
vector<string> walls;
int neighbour[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
void dfs(int i, int j)
{
    // cout << roomCount << " " << i << " " << j << endl;
    visited[i][j] = 1;
 
    int ii, jj;
    for (int ni = 0; ni < 4; ni++)
    {
        ii = i + neighbour[ni][0];
        jj = j + neighbour[ni][1];
        // cout << i << " " << j << " -> " << ii << " " << jj << " -> " << walls[ii][jj] << " " << visited[ii][jj] << endl;
        if (ii < n && jj < m && ii >= 0 && jj >= 0 && visited[ii][jj] == 0 && walls[ii][jj] == '.')
        {
            // cout << "dfs" << endl;
            dfs(ii, jj);
        }
    }
 
    return;
}
 
void findRooms()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << visited[i][j] << " ";
            if (visited[i][j] == 0 && walls[i][j] == '.')
            {
                roomCount++;
                dfs(i, j);
            }
        }
        // cout <<endl;
    }
}
 
int main()
{
    cin >> n >> m;
    walls.resize(n);
    visited.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> walls[i];
    }
 
    findRooms();
 
    cout << roomCount;
 
    return 0;
}
