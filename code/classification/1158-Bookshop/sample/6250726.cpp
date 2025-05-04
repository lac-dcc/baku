#include <bits/stdc++.h>
using namespace std;
// #define int long long
 
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int n, x;
  cin >> n >> x;
  int arr[n + 1];
  int arr1[n + 1];
  int dp[n + 1][x + 1];
 
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
 
  for (int i = 1; i <= n; i++)
    cin >> arr1[i];
 
  for (int i = 0; i <= x; i++)
    dp[0][i] = 0;
  for (int i = 0; i < n + 1; i++)
  {
    dp[i][0] = 0;
  }
 
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= x; j++)
    {
      if (arr[i] > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr1[i]);
      }
    }
  }
    cout << dp[n][x] << "\n";
 
    return 0;
  }
