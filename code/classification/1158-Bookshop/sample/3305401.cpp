#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x;
  cin >> n >> x;
  vector<int> h(n);
  for(int i = 0; i<n;i++){
    cin >> h[i];
  }
  vector<int> s(n);
  for(int i = 0; i<n;i++){
    cin >> s[i];
  }
  int dp[2][x+1];
  bool f = false;
  for(int i = 0; i<=n;i++){
    for(int j = 0; j<=x;j++){
      if(i==0 || j==0){
        dp[f][j] = 0;
      }else{
        if((j-h[i-1])>=0){
          dp[f][j] = max(dp[!f][j],dp[!f][j-h[i-1]]+s[i-1]);
        }else{
          dp[f][j] = dp[!f][j];
        }
      }
    }
    f = !f;
  }
  cout << dp[!f][x]<<'\n';
  
}
