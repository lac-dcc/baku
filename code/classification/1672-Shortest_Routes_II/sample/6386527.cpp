#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n,m,q;
int d[505][505][2];
int inf = 1e18;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                d[i][j][0] = inf;
    for (int i = 1; i <= m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        d[x][y][0] = min(d[x][y][0],z);
        d[y][x][0] = min(d[y][x][0],z);
    }
    int p = 1;
    for (int k = 1; k <= n; k++,p = 1 - p)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j][p] = min(d[i][j][1 - p],d[i][k][1 - p] + d[k][j][1 - p]);
    p = 1 - p;
    for (int i = 1; i <= q; i++)
    {
        int x,y;
        cin >> x >> y;
        if (d[x][y][p] == inf)
            cout << -1 << '\n';
        else
            cout << d[x][y][p] << '\n';
    }
    return 0;
}
