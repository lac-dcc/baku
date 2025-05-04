// Nisarg Goagte
// VNIT
 
#include<bits/stdc++.h>
#define int long long 
#define TESTCASES false
#define FASTIO true
#define FF first
#define SS second
 
const int inf  = (int)1e18 + 1;
const int SIZE = (int)1e5+3;
const int MOD = (int)1e9+7;
using namespace std;
 
int solve()
{
    int i,j,ans=0;
    string a,b,temp;
 
    cin>>a>>b;
    
    int n = a.size(), m = b.size();
    if(n>m)
    {
        temp=a;
        a=b;
        b=temp;
        ans=n;
        n=m;
        m=ans;
    }
 
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==0)
                dp[i][j]=j;
            if(j==0)
                dp[i][j]=i;
        }
    }
    
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
        {
            // delete ele from a
            dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
 
            // add to b
            dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);
 
            // replace
            dp[i][j] = min(dp[i][j],dp[i-1][j-1] + 1);
 
            if(a[i-1] == b[j-1])
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}
 
void main_code()
{
	int i,j,n,k;
    cout<<solve()<<endl;
}
 
signed main()
{
    if(FASTIO)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int T = 1;
 
    if(TESTCASES)
        cin >> T;
 
    while(T--)
        main_code();
    
}
