#include <bits/stdc++.h>
using namespace std;
 
bool visited[1010][1010];
char graph[1010][1010];
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int n, m, ans = 0;
 
bool isValid(int x, int y)
{
    if (x < 0)
        return false;
    if (x >= n)
        return false;
    if (y < 0)
        return false;
    if (y >= m)
        return false;
    if (graph[x][y] == '#')
        return false;
 
    return true;
}
 
void DFS(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
 
        if (isValid(newX, newY))
        {
            if (!visited[newX][newY])
            {
                DFS(newX, newY);
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
 
    // Taking input for the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            visited[i][j] = false;
        }
    }
 
    // Solution
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' and !visited[i][j])
            {
                DFS(i, j);
                ans++;
            }
        }
    }
 
    cout << ans << "\n";
 
    return 0;
}
