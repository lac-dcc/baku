#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n, x;
    cin >> n >> x;
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int dp[x];
    for (long long int i = 0; i < x; i++)
    {
        dp[i] = INT_MAX;
    }
    for (long long int i = 0; i < n; i++)
    {
        if (arr[i] - 1 < x)
        {
            dp[arr[i] - 1] = 1;
        }
    }
    for (long long int i = 0; i < x; i++)
    {
 
        for (long long int j = 0; j < n; j++)
        {
            if ((i - arr[j]) >= 0)
            {
 
                dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
            }
        }
    }
    if (dp[x - 1] < INT_MAX)
    {
        cout << dp[x - 1];
    }
    else
        cout << "-1";
 
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
 
    return 0;
}