#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ff first
#define ss second
#define pb push_back
const long long int MOD  = 1000000007;
 
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
// declare variable as:  ordered_set A;
 
#define endl '\n' // make sure to comment this in interaction problems
const int MAXN = 500;
lli dp[MAXN+1][MAXN+1];
const lli INF = 1e18;
void floydWarshal(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    int u, v; lli w;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        dp[i][j] = (i == j)?0:INF;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }
    floydWarshal(n);
    while(q--)
    {
        cin >> u >> v;
        if(dp[u][v] == INF)
        cout << "-1" << endl;
        else
        cout << dp[u][v] << endl;
    }
    return 0;
}
