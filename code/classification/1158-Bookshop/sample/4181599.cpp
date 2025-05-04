#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define mod 1000000007
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> price, page;
    price.push_back(0);
    page.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        price.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        page.push_back(a);
    }
    // vector<pair<int,int>>vp;
    // for(int i=0;i<n;i++)
    // {
    //     vp.push_back({price[i],page[i]});
    // }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // sort(vp.begin(),vp.end(),cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int money = 1; money <= m; money++)
        {
            int op1 = 0;
            if (i != 1)
                op1 = dp[i - 1][money];
            int op2 = 0;
            if (money >= price[i])
                op2 = page[i] + dp[i - 1][money - price[i]];
            dp[i][money] = max(op1, op2);
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout << dp[n][m];
    return 0;
}