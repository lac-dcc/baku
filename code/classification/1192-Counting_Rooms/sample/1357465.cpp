//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <queue>
#include <map>
using namespace std;
 
#define ii pair <int, int>
#define lli long long
#define pb push_back
#define X first
#define Y second
 
const int Mod = 1E9 + 7;
const int Inf = 1E9 + 7;
const int N = 1e3 + 10;
const int cx[4] = {0, 0, 1, -1};
const int cy[4] = {1, -1, 0, 0};
 
int n, m;
bool visited[N][N];
char a[N][N];
 
void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
}
 
bool Inside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == '.';
}
 
void BFS(int x, int y)
{
    visited[x][y] = true;
    deque <ii> DQ;
    DQ.push_back({x, y});
    while (DQ.size()) {
        int ux = DQ.front().X;
        int uy = DQ.front().Y;
        DQ.pop_front();
        for (int i = 0; i < 4; i++) {
            int vx = ux + cx[i];
            int vy = uy + cy[i];
            if (Inside(vx, vy) && !visited[vx][vy]) {
                visited[vx][vy] = true;
                DQ.push_back({vx, vy});
            }
        }
    }
}
 
void Solve()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (Inside(i, j) && !visited[i][j]) {
        res++;
        BFS(i, j);
    }
    cout << res;
}
 
#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}
 
 
