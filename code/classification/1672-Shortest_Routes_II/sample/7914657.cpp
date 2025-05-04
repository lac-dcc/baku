// Author: Akshay A Baiju
// Problem:
// URL:
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n" // not to be used in interactive problems
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define PI 3.141592653589793238462
 
const int M = 1e9 + 7;
const int MOD = 998244353;
const int N = 2e5 + 7;
const ll inf = 1e18;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
void solve()
{
    // floyd-warshall
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        dp[u][v] = dp[v][u] = min(dp[u][v], wt);
    }
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] != inf && dp[k][j] != inf)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll ans = dp[u][v] == inf ? -1 : dp[u][v];
        cout << ans << endl;
    }
}
 
int main()
{
    sync;
    int t = 1;
    // cin >> t;
    for (int test = 1; test <= t; test++)
    {
        solve();
        cout << endl;
    }
    return 0;
}
