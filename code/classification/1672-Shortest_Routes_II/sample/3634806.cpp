#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int MAXN = 587;
ll d[MAXN][MAXN];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, q, a, b, c;
    cin >> n >> m >> q;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = LLONG_MAX / 2;
        }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (c < d[a][b])
            d[a][b] = c;
        if (c < d[b][a])
            d[b][a] = c;
    }
 
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
 
    while (q--)
    {
        cin >> a >> b;
        if (d[a][b] == LLONG_MAX / 2)
            cout << "-1\n";
        else
            cout << d[a][b] << "\n";
    }
 
    return 0;
}
