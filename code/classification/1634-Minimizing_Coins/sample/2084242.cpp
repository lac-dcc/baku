#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
 
      long long int n,x; cin >> n >> x;
      long long dp[x+1];
      memset(dp,0,sizeof(dp));
      long long int coins[n];
      for(int i = 0; i < n; i++) cin >> coins[i];
	          for(long long int i = 1; i <= x; i++){
				  dp[i] = INT_MAX;
				  for(long long int j = 0; j < n; j++){
					  if(coins[j] <= i)
					   dp[i] = min(dp[i],dp[i-coins[j]]+1);
				  }
			  }
      if(dp[x] >= INT_MAX) cout << -1;
      else cout << dp[x];
return 0;
}
