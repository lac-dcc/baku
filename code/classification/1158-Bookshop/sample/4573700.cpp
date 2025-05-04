#include <bits/stdc++.h>
using namespace std;
 
//-------------------------------------------------
#define mod 1000000007
 
//-------------------------------------------------
 
/***********************SOLVE**********************/
 
void iSolve(int n, int cost, int *price, int *pages)
{
    // dp[i][x]: max no of pages for ith book at x cost
    int dp[n + 1][cost + 1];
    // vector<vector<int>> dp(n + 1, vector<int>(cost + 1, 0));
 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cost; j++)
        {
 
            dp[i][j] = 0;
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int money = 0; money <= cost; money++)
        {
            int pick = (money < price[i - 1]) ? 0 : pages[i - 1] + dp[i - 1][money - price[i - 1]];
            int noPick = dp[i - 1][money];
 
            dp[i][money] = max(pick, noPick);
        }
    }
 
    cout << dp[n][cost];
}
 
void solve()
{
    int n, cost;
    cin >> n >> cost;
 
    int price[1000];
    int pages[1000];
 
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
 
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
 
    iSolve(n, cost, price, pages);
}
 
/*=======================MAIN========================*/
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    // cin >> t;
 
    while (t--)
    {
        solve();
        cout << "\n";
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}