#include <bits/stdc++.h>
using namespace std;
 
int n,x,dp[1000010]={0},c;  
 
int main(){  
  cin>>n>>x;
  dp[0]=1;
  for(int i=1;i<=n;i++){
    cin>>c;
    for(int j=c;j<=x;j++)dp[j]=(dp[j]+dp[j-c])%1000000007;
  }
  cout<<dp[x]<<endl;
return 0;}