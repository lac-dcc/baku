#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	int c[n+1],v[n+1];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>v[i];
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++) 
		{
			dp[i][j]=dp[i-1][j];
			if(j>=c[i])
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]]+v[i]);
			}
		}
	}
	cout<<dp[n][k];
}