#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
int n;
vector<long long> coins(1e6), dp(1e6 + 1, -1);
 
long long fun(int x)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= x)
        {
            int t = x - coins[i];
            if (dp[t] == -1)
            {
                dp[t] = fun(t);
            }
            ans = (ans % mod + dp[t] % mod) % mod;
        }
    }
    dp[x] = ans;
    return ans;
}
 
int main()
{
    int x;
    cin >> n >> x;
    coins.resize(n);
    dp.resize(x + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    cout << fun(x);
    return 0;
}
