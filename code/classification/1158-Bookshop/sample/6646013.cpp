#include<bits/stdc++.h>
using namespace std;
 
int mod =1e9 + 7;
 
 
// form 1 : Either select or not select (knapsack pattern)
 
// dp[i][x] = maximum number of pages we can get for price at most x, only buying among the first i books.
 
 
 
int helper(int i ,int n,vector<pair<int,int>>&arr,vector<vector<int>>&dp){
    if(i<0 || n<0){
       return 0;
    }
    if(i==0){
       if(arr[i].first<=n){
         return arr[i].second;
       }
       return 0;
    }
    if(n == 0){
       return 0;
    }
    if(dp[i][n] != -1){
        return dp[i][n];
    }
    int take = 0;
    if(arr[i].first <=n)
     take = arr[i].second + helper(i-1,n-arr[i].first,arr,dp);
    int nottake = 0 + helper(i-1,n,arr,dp);
    return dp[i][n] = max(take,nottake);
}
 
 
 
void solve(){
   int n,m;
   cin>>n>>m;
   vector<pair<int,int>>arr(n);
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i =0;i<n;i++){
      int val;
      cin>>val;
       arr[i].first = val;
   }
   for(int i =0;i<n;i++){
       int val;
       cin>>val;
       arr[i].second = val;
   }
  
  //  int ans = helper(n-1,m,arr,dp);
 //
 
 
 
   //  Method 2 : 
 
 
   for(int i = 1;i<=n;i++){
     for(int j =0;j<=m;j++){
        dp[i][j] = dp[i-1][j];
        if(j-arr[i-1].first>=0){
           dp[i][j]  = max( dp[i][j], arr[i-1].second + dp[i-1][j-arr[i-1].first]);
        }
     }
   }
   cout<<dp[n][m]<<endl;
 
}
 
int main(){
  solve();
  return 0;
}
