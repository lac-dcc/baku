# include<bits/stdc++.h>
using namespace std;
# define inf 1000000000
# define mod 1000000007
 long long  dp[1000002];
 
int main()
{
 
    int n,x;
    cin>>n>>x;
     fill(dp+1, dp+x+1, 0);
     dp[0]=1;
  int coin;
  vector<int> coin1;
  coin1.resize(n);
  ///taking coin as input
   for(int i=0;i<n;i++)
        cin>>coin1[i];
 
 
    /// now as we know each coin has chance to use after any other coin
    for(int i=0;i<=x;i++) {
 
        if(dp[i]!=0)
        for(int j=0;j<n;j++){
                 coin=coin1[j];
                 if(i+coin<=x){
                dp[i+coin]=(dp[i+coin]+dp[i])%mod;
 
                 }
 
        }
 
    }
 
     cout<<dp[x]<<endl;
 
 
 
    return 0;
}
