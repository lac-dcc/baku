#include<bits/stdc++.h>
 
#define ll long long
using namespace std;
const int mx = 1e6;
const ll mod = 1e9+7;
ll dp[5002][5002];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll n,m;
	string s1,s2;
	cin>>s1>>s2;
	n = s1.size();
	m = s2.size();
	for(int i = 0;i<=m;i++)
		dp[0][i] = i;
	for(int i = 0;i<=n;i++)
		dp[i][0]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
			else
			{
				ll a = dp[i-1][j-1]+1;
				ll b = dp[i-1][j]+1;
				ll c = dp[i][j-1]+1;
				dp[i][j] = min({a,b,c});
			}
		}
	}
	cout<<dp[n][m];
}