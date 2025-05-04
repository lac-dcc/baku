#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int n,amount=0, mod=1e9+7;
  
  cin>>n>>amount;
  vector <long long>coins(n),dp(amount+1);
 
  for(int i=0;i<n;i++)
   cin>>coins[i];
 
  sort(coins.begin(),coins.end());
  dp[0]=1;
  
  for (int i = 1; i <=amount; i++) 
  {
    for(int j=0;j<coins.size();j++)
    {    
        if(i-coins[j]>=0)
        {
          dp[i]+=dp[i-coins[j]];
          dp[i]%=mod;
          }
        else break;
    }
  }
  
  cout<<dp[amount]<<endl;
}
 