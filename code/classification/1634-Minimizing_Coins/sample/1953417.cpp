#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,x;
	cin>>n>>x;
	vector<long> a(n);
	//memset(dp,sizeof(dp),0);
	for(long i=0;i<n;i++)
	cin>>a[i];
	vector<long> dp(x+1,LONG_MAX);
    dp[0]=0;
	sort(a.begin(),a.end(),greater<long>());
	long min1=LONG_MAX;
	for(long long i=1;i<=x;i++)
	{	long x1=LONG_MAX;
		for(long j=0;j<n;j++)
		{
			if(a[j]>i)
			continue;
			else if(dp[i-a[j]]+1>0)
			x1=min(x1,dp[i-a[j]]+1);
		}
        if(x1==LONG_MAX)
             dp[i]=-1; 
     else
		dp[i]=x1;
	}
	cout<<dp[x]<<endl;
}