#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int n, x;
	cin>>n>>x;
	int coins[n];
	for(int i=0;i<n;i++) cin>>coins[i];
	
	vector<int>dp(x+1,INT_MAX);
	dp[0]=0;
	 for(int i=1;i<=x;i++)
	 { 
	    for(int j=0;j<n;j++) 
	    {
	           if(i-coins[j]>=0) {
	           if(dp[i]<1+dp[i-coins[j]])
	             dp[i]=dp[i];
	             else
	             dp[i]=1+dp[i-coins[j]];
	           }
	    }
	 }
	if(dp[x]==INT_MAX) cout<<-1;
	else
	cout<<dp[x];
}