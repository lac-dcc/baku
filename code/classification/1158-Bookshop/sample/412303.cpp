#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
const int N = 1010;
const int M = 1e5 + 7;
const int INF = 1e9;
 
int n,k;
int dp[N][M];
int val[N],page[N];
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp,0,sizeof(dp));
 
	cin>>n>>k;
 
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<=n;++i) cin>>page[i];
 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
		{
			if(val[i] <= j)
			{
				
				dp[i][j] = max(  dp[i-1][j-val[i]] + page[i]  , dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
 
		}
 
	cout<<dp[n][k];
}
