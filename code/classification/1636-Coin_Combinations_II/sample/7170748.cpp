#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
 
int main() {
    
     long long int n,S;
     cin>>n>>S;
     
     long long int coins[n];
     
     for(int i=0;i<n;i++)
      cin>>coins[i];
      
     vector<long long int> dp(S+1,0);
     
     dp[0]=1;
     
      for(int j=0;j<n;j++)
      {
        for(int i=1;i<=S;i++)
        { 
        
         
             if(i-coins[j]>=0)
             {
                 dp[i] += dp[i-coins[j]];
                 dp[i] %= mod;
             }
         }
     }
     
     cout<<dp[S];
	return 0;
}
