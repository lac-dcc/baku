#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n + 1), pages(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> prices[i];
    for (int i = 1; i <= n; i++)
        cin >> pages[i];
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
 
    for (int i = 1; i <= n; i++)
    {
        for (int val = 1; val <= x; val++)
        {
            dp[i][val] = dp[i - 1][val];
            if (prices[i] <= val)
            {
                dp[i][val] = max(dp[i][val], pages[i] + dp[i - 1][val - prices[i]]);
            }
        }
    }
 
    cout << dp[n][x];
}