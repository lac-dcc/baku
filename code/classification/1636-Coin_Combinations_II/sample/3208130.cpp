#include <bits/stdc++.h>
 
using namespace std;
  int coins[105];
  int dp[105][1000005];
   int x;
   int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
 
  cin >> n;
  cin >> x;
  for (int i = 0; i < n; i++) cin >> coins[i];
   
  for (int i = 0; i < n; i++)
  {
  	for (int l = 1; l <= x; l++)
  	{
  		if ((i == 0) && (l-coins[0] < 0)) dp[i][l] = 0;
		else if (i == 0) 
		{
			if (l%coins[0] == 0) dp[i][l] = 1;
			else dp[i][l] = 0;
		 } 
		if (i > 0 && l-coins[i] < 0) dp[i][l] = dp[i-1][l];
		else if (i > 0 && l-coins[i] == 0) dp[i][l] = (dp[i-1][l] + 1)%1000000007;
		else if (i > 0) dp[i][l] = (dp[i-1][l]%1000000007 + dp[i][l-coins[i]]%1000000007)%1000000007;
	  }
  }cout << dp[n-1][x];
  
  
  
  return 0;
}
	