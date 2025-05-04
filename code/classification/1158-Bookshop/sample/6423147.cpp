#include<bits/stdc++.h>
  
using namespace std;
using ll = long long;
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>v(n);
    for(pair<int,int> &i:v) cin>>i.first;
    for(pair<int,int> &i:v) cin>>i.second;
    vector<vector<int>>dp(n+1,vector<int>(x+3));
   // dp[0][0]=1;
    int mx = 0;
    for(int i =1;i<=n;i++){
        for(int j =0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(v[i-1].first<=j && v[i-1].first<=x+1){
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i-1].first]+v[i-1].second);
                mx = max(mx,dp[i][j]);
            }
        }
    }
    // for(int i = 0;i<=x;i++){
    //     cout<<dp[1][i]<<endl;
    // }
    cout<<mx<<endl;
}
