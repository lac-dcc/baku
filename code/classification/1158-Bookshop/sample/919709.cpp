#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
int main()
{
	int n,x,t;
	cin>>n>>x;
 
	// vector<int> h(n+1),s(n+1);
	int h[n+1],s[n+1];
	
	for(int i=1;i<=n;i++){cin>>h[i];}
	for(int i=1;i<=n;++i){cin>>s[i];}
 
	// for(int i=0;i<n;i++){cin>>t;h.push_back(t);}
	// for(int i=0;i<n;++i){cin>>t;s.push_back(t);}
 
	vector< vector<int> > dp(n+1, vector<int> (x+1));
 
	for(int i=0;i<=x;++i)dp[0][i]=0;
	for(int i=0;i<=n;++i)dp[i][0]=0;
 
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=x;++j)
		{
			if(j<h[i])dp[i][j]=dp[i-1][j];
			else{dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i]]+s[i]);}
		}
	}
 
	// for(int i=0;i<=n;++i)
	// {
	// 	for(int j=0;j<=x;++j)cout<<dp[i][j];
	// 		cout<<endl;
	// }
 
	cout<<dp[n][x];
}
