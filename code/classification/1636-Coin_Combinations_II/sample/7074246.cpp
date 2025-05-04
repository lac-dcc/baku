#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[1000001];
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x ; j++)
        {
            if (j - v[i - 1] >= 0)
            {
                dp[j] += dp[j - v[i - 1]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[x];
}