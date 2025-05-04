#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string a,b;
int dp[5005][5005];
int n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    n=a.size();
    m=b.size();
    a=" "+a;
    b=" "+b;
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(i!=0||j!=0)
            {
                dp[i][j]=1e9;
                if(i-1>=0)
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                if(j-1>=0)
                    dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
                if(i-1>=0&&j-1>=0)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j]));
            }
    cout<<dp[n][m];
    return 0;
}
