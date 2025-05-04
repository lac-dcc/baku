#include<bits/stdc++.h>
using namespace std;
 
void booster()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
 
int main()
{
    booster();
    int n, x; cin >> n >> x;
    int price[n + 1], pages[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
 
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
 
    int dp[n + 1][x + 1];
 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = 0;
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (price[i] <= j)
            {
                dp[i][j] = max(dp[i][j], pages[i] + dp[i - 1][j - price[i]]);
            }
        }
    }
 
    cout << dp[n][x];
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*
1 - https://leetcode.com/problems/frequency-of-the-most-frequent-element/submissions/
2 - https://leetcode.com/problems/sort-characters-by-frequency/submissions/
3 - https://leetcode.com/problems/k-closest-points-to-origin/submissions/
4 - https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/submissions/
 
5 - https: //leetcode.com/problems/xor-queries-of-a-subarray/discuss/1016180/c%2B%2B-understand-in-just-Two-processes-(Beats-99)
 
6 - https://leetcode.com/problems/binary-search-tree-iterator/discuss/965553/C%2B%2B-or-Using-simple-array
*/
