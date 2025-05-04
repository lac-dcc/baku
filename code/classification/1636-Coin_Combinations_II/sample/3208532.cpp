#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,k;
    cin >> n >> k;
 
    vector<int> coins(n);
    for (auto &i : coins) cin >> i;
 
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
 
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
 
    for (int riga = 1; riga <= n; riga++)
    {
        int moneta = coins[riga-1];
        for (int col = 1; col <= k; col++)
        {
            dp[riga][col] += dp[riga-1][col] + (col-moneta >= 0 ? dp[riga][col-moneta] : 0);
            dp[riga][col] %= (int)(1e9+7);
        }
    }
 
    cout << dp[n][k] << endl;
}