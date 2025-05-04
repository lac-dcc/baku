#include<bits/stdc++.h>
using namespace std;
 
// #define int long long
 
int solve(int ind,int x,vector<int> &price,vector<int> &page,vector<vector<int>> &dp){
 
    if(x<0) return INT_MIN;
 
    if(x==0 || ind==0) return 0;
 
    if(dp[ind][x]!=-1) return dp[ind][x];
 
    int ans=INT_MIN;
    //take
    ans=max(ans,page[ind-1]+solve(ind-1,x-price[ind-1],price,page,dp));
 
    //nottake
    ans=max(ans,solve(ind-1,x,price,page,dp));
    
    return dp[ind][x]=ans;
 
}
 
int32_t main()
{
    int n,x;
    cin>>n>>x;
    vector<int> price(n),page(n);
 
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
 
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
 
    // vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
    vector<int> prev(x+1,0);
 
    // for(int i=0;i<n;i++){
    //     dp[i][0]=0;
    // }
 
    // for(int j=0;j<=x;j++){
    //     if(price[0]<=j)
    //     dp[0][j]=page[0];
    // }
 
    for(int i=1;i<=n;i++){
        vector<int> cur(x+1,0);
        for(int j=1;j<=x;j++){
            int ans=INT_MIN;
            //take
            if(price[i-1]<=j)
            ans=max(ans,page[i-1]+prev[j-price[i-1]]);
 
            //nottake
            ans=max(ans,prev[j]);
 
            cur[j]=ans;
        }
        prev=cur;
    }
 
    cout<<prev[x]<<endl;
    return 0;
}
