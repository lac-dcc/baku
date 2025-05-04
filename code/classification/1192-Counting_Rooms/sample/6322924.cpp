#include <bits/stdc++.h>
#define file "test2"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define MaxN 1001
using namespace std;
ll maxx = -1e18, minn = 1e18;
ll n, m;
char a[MaxN][MaxN];
bool visited[MaxN][MaxN];
ll dx[4] = {-1, 0, 0, 1};
ll dy[4] = {0, -1, 1, 0};
void dfs(ll i, ll j)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        ll i1 = i + dx[k];
        ll j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.' && !visited[i1][j1])
        {
            dfs(i1, j1);
        }
    }
}
void bfs(ll i, ll j)
{
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            ll i1 = v.fi + dx[k];
            ll j1 = v.se + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '.' && !visited[i1][j1])
            {
                visited[i1][j1] = true;
                q.push({i1, j1});
            }
        }
    }
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen(file ".inp", "r", stdin);
    freopen(file ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.' && !visited[i][j])
            {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt;
}
