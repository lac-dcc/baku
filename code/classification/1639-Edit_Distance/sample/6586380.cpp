#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[5001][5001];
const int mod = 1e9+7;
 
signed main(){
  string s,t;
  cin>>s>>t;
  int n=s.size(), m=t.size();
  for(int i=n;i>=0;i--){
    for(int j=m;j>=0;j--){
      if(i==n || j==m){
        dp[i][j] = (n-i)+(m-j);
      }else{
        dp[i][j] = min({1+dp[i+1][j],1+dp[i][j+1],dp[i+1][j+1]+(!(s[i]==t[j]))});
      }
    }
  }
  cout<<dp[0][0]<<endl;
}
