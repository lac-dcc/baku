#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,tar;
	cin>>n>>tar;
	vector<ll>v(n,0);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<vector<int>>dp(n,vector<int>(tar+1,0));
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		{
			for(int j=0;j<v[i];j++)
			{
				dp[i][j]=(dp[i][j]%1000000007+dp[i-1][j]%1000000007)%1000000007;
			}
		}
		for(int j=v[i];j<=tar;j++)
		{
			if(i==0)
			{
				dp[i][j]=(dp[i][j]%1000000007 + dp[i][j-v[i]]%1000000007)%1000000007;
			}
			else
			{
				dp[i][j]=(dp[i-1][j]%1000000007+dp[i][j-v[i]]%1000000007)%1000000007;
			}
		}
	}
	cout<<dp[n-1][tar];
	return 0;
}
