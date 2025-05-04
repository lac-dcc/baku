#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main()
{
 
    ll n, sum;
    cin >> n >> sum;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int dp[n + 1][sum + 1];
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
            {
                int op1 = (v[i] > j) ? 0 : dp[i][j - v[i]];
                int op2 = (i == 1) ? 0 : dp[i - 1][j];
                dp[i][j] = (op1 + op2) % 1000000007;
            }
        }
    }
 
    cout << dp[n][sum];
 
    return 0;
}
