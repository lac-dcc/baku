#include <stdio.h>
#include <string.h>
 
#define SIZE 1000
 
int uf[SIZE * SIZE];
int 
find (int u)
{
    return uf[u] < 0 ? u : (uf[u] = find(uf[u]));
}
 
void
join (int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (u > v)
        uf[u] = v;
    else
      {
        if(uf[u] == uf[v])
            uf[u]--;
        uf[v] = u;
      }
}
 
int 
main() 
{
    int n, m, i, j, ans;
    char g[SIZE][SIZE];
 
    scanf ("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", g[i]);
    memset(uf, -1, sizeof uf);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
          {
            if(i > 0 && g[i][j] == '.' && g[i - 1][j] == '.')
                join(i * m + j, (i - 1) * m + j);
            if(j > 0 && g[i][j] == '.' && g[i][j - 1] == '.')
                join(i * m + j, i * m + j - 1);
          }
    ans = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if(g[i][j] == '.' && uf[i * m + j] < 0)
                ans++;
    printf("%d\n", ans);
}


