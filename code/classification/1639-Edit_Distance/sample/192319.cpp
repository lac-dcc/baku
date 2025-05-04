#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
int main()
{
    fast;
    string a,b;
    int n,m;
    cin>>a>>b;
    n=a.size(),m=b.size();
    //int dp[n+1][m+1]={};
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i=0; i<=n; i++) dp[i][m]=n-i;
    for(int i=0; i<=m; i++) dp[n][i]=m-i;
    for(int i=n-1; i>-1; i--)
    {
        for(int j=m-1; j>-1; j--)
        {
            if(a[i]!=b[j])
            {
                dp[i][j]=min({dp[i][j+1],dp[i+1][j+1],dp[i+1][j]})+1;
            }
            else dp[i][j]=dp[i+1][j+1];
        }
    }
    cout<<dp[0][0];
    return 0;
}
