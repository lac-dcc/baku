#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve()
{
    string a,b;cin>>a>>b;
    a='@'+a;
    b='@'+b;
    vector<vector<int>>dp(5005,vector<int>(5005,1e9));
    dp[0][0]=0;
    for(int i=1;i<a.size();i++)
    {
        dp[i][0]=i;
    }
    for(int j=1;j<b.size();j++)
    {
        dp[0][j]=j;
    }
    for(int i=1;i<a.size();i++)
    {
        for(int j=1;j<b.size();j++)
        {
            dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(a[i]!=b[j])});
        }
    }
    cout<<dp[a.size()-1][b.size()-1];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int ut=1;
//    cin>>ut;
    while(ut--)solve();
}