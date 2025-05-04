#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define pb push_back
#define buffer cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define class_operator bool operator < (const movie & rhs) const {return en<rhs.en;}
 
using namespace std;
 
int main()
{
	IOS
		string a,b;
		cin>>a>>b;
		int m=a.length();
		int n=b.length();
		vector <vector <int>> dp(m+1,vector <int>(n+1,0));
		dp[0][0]=0;
		for(int i=1; i<=m; i++)
            dp[i][0]=i;
        for(int j=1; j<=n; j++)
            dp[0][j]=j;
		for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=min(min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1,dp[i-1][j-1]);
                }
                else
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
        //int lcs=dp[m][n];
        //int mx=max(m,n);
        cout<<dp[m][n]<<endl;
 
	return 0;
}
 
