#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll adjMat[500][500];
ll dist[500][500];
 
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMat[i][j] = LLONG_MAX;
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        adjMat[a][b] = adjMat[b][a] = min(adjMat[a][b], c);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (adjMat[i][j])
                dist[i][j] = adjMat[i][j];
            else
                dist[i][j] = LLONG_MAX;
        }
    }
 
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << ((dist[a][b] != LLONG_MAX) ? dist[a][b] : -1) << endl;
    }
 
    return 0;
}
