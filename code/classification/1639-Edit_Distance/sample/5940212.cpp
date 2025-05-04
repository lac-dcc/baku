#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;cin>>a>>b;
    int n=a.length(),m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,2e9));
    dp[0][0]=0;
    for(int j=0;j<=n;j++){
        for(int i=0;i<=m;i++){
            if(j!=0) dp[j][i]=min(dp[j][i],dp[j-1][i] + 1);
            if(i!=0) dp[j][i]=min(dp[j][i],dp[j][i-1] + 1);
            if(j!=0&&i!=0) dp[j][i]=min(dp[j][i],dp[j-1][i-1] + (a[j-1]!=b[i-1]));
        }
    }
    cout<<dp[n][m];
    return 0;
}