#include <bits/stdc++.h>
using namespace std;
 
// void solve()
// {
 
// }
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
 
    // n is no. of elements
    // x is the budget
 
    vector<int> price(n), pages(n);
 
    for (int &v : price)
        cin >> v;
    for (int &v : pages)
        cin >> v;
 
    vector<vector<int> > dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            // dp[i][j] = dp[i - 1][j];
            int left = j - price[i - 1];
            if (left >= 0)
            {
                dp[i][j] = max(dp[i-1][j], dp[i - 1][left] + pages[i - 1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
