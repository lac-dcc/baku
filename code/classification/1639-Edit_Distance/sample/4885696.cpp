#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string x,y;
    cin>>x>>y;
    int m=x.size(),n=y.size();    
    vector<vector<long long>>dp(m+1,vector<long long>(n+1,1e9));
    dp[0][0]=0;
    for(int i=1;i<m;i++)dp[i][0]=i;
    for(int i=1;i<n;i++)dp[0][i]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])dp[i][j]=dp[i-1][j-1];
            dp[i][j]=min(dp[i][j],(min(dp[i-1][j],dp[i][j-1])+1));
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[m][n];
    return 0;
}