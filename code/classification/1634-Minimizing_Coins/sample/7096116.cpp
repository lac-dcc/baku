#define ll long long
#include<bits/stdc++.h>
using namespace std;
 
int solve(int amount,vector<int>&coins,vector<int> &dp){
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int cnt= solve(amount-coins[i],coins,dp);
        if(cnt!=INT_MAX){
            ans=min(ans,1+cnt);
        }
    }
    return dp[amount]=ans;
}
 
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(1e6+1,-1);
    int ans=solve(sum,arr,dp);
    if(ans==INT_MAX) ans=-1;
    cout<<ans;
    return 0;
}
