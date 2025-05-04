#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<vector<long long>> a(n + 1, vector<long long>(n + 1, LONG_LONG_MAX / 2));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long z;
        scanf("%d%d%lld", &x, &y, &z);
        a[x][y] = min(z, a[x][y]);
        a[y][x] = min(z, a[x][y]);
    }
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << (a[x][y] == LONG_LONG_MAX / 2 ? -1 : a[x][y]) << endl;
    }
    return 0;
}
