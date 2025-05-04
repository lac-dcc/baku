#include <bits/stdc++.h>
#define int long long
using namespace std;
 
#define mod 1000000007
#define pi 2 * acos(0.0)
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
 
void fun()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
/* DON'T LIMIT YOUR CHALLENGES, CHALLENGE YOUR LIMITS */
 
void solve()
{
    string str, str1;
    cin >> str >> str1;
 
    vector<vector<int>> dp(str.length() + 1, vector<int>(str1.length() + 1));
 
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 0; j <= str1.length(); j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0 && j > 0)
                dp[i][j] = j;
            else if (j == 0 && i > 0)
                dp[i][j] = i;
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (str[i - 1] == str1[j - 1] ? 0 : 1));
            }
        }
    }
 
    cout << dp[str.length()][str1.length()];
}
 
signed main()
{
    //fun();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
 
    return 0;
}
