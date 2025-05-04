#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;cin>>n>>x;
    vector<pair<int,int>>vec(n);
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        vec[i].first=temp;
    }
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        vec[i].second=temp;
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(vec[i-1].first<=j) dp[i][j]=max(dp[i-1][j-vec[i-1].first]+vec[i-1].second,dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][x]<<'\n';
}
