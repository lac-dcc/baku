#include<bits/stdc++.h>
#define ll long long int
#include<limits.h>
using namespace std;
int main()
{
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1,INT_MAX);
	dp[0]=0;
	vector<ll> coins(n);
	for(int i=0;i<n;i++)
	cin>>coins[i];
	for(int i=1;i<=x;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(coins[j]>i) continue;
			dp[i]=min(dp[i],1+dp[i-coins[j]]);
		}
	}
	if(dp[x]==INT_MAX) cout<<-1;
	else
	cout<<dp[x];
	return 0;
}
