#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
const int N = 1e3 + 7;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
typedef pair<int, int> ii;
 
int n, m;
int a[N][N], cx[N][N];
int ans = 0;
 
void bfs(int x, int y)
{
    queue<ii> q;
    q.push({x, y});
    cx[x][y] = 1;
//    cout << x << " " << y << "\n\n";
    while(q.size())
    {
        int x_ = q.front().fi, y_ = q.front().se;
        q.pop();
 
//        cout << x_ << " " << y_ << "\n";
 
        for(int k = 0; k < 4; k++)
        {
            int u = x_ + dx[k];
            int v = y_ + dy[k];
//            cout << u << " " << v << "\n";
            if(u < 1 || v < 1 || u > n || v > m || cx[u][v] || !a[u][v]) continue;
            cx[u][v] = 1;
//            cout << u << " " << v << "\n";
            q.push({u, v});
        }
    }
//    cout << "\n";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
 
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        a[i][j] = 0;
        if(x == '.') a[i][j] = 1;
    }
 
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= m; j++) cout << a[i][j] << " ";
//        cout << "\n";
//    }
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] && !cx[i][j]) ans ++, bfs(i, j);
 
    cout << ans;
}
 
