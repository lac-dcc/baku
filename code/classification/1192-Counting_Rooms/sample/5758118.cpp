#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int N=1009;
int n, m, vis[N][N];
string a[N];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};
bool in(int i,int j) {
    return i>-1 && i<n && j>-1 && j<m;
}
void dfs(int x, int y) {
    vis[x][y]=1;
    for(int k=0; k<4; ++k) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(in(nx,ny) && !vis[nx][ny] && a[nx][ny]=='.')
            dfs(nx,ny);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    int ans=0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(!vis[i][j] && a[i][j]=='.') {
                dfs(i, j);
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
