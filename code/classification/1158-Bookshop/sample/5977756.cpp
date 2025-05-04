#include<bits/stdc++.h>
using namespace std;
 
int mod = 1e9 +7; int main(){ int n,x; cin>>n>>x; pair<int,int> h[n];
 
for(int i=0;i<n;i++){
    cin>>h[i].first;
}
for(int i=0;i<n;i++){
    cin>>h[i].second;
}
int dp[n+1][x+1];
dp[0][0]=0;
for(int i=0;i<=n;i++){
    dp[i][0] = 0;
}
for(int i=0;i<=x;i++){dp[0][i]=0;}
for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
        dp[i][j] = dp[i-1][j];
        if(j>=h[i-1].first){
            dp[i][j] = max(dp[i-1][j- h[i-1].first]+h[i-1].second,dp[i][j]);
        }
        dp[i][j] %= mod;
    }
}
cout<<dp[n][x]<<"\n"; }