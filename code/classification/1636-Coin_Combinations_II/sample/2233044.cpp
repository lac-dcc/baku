#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
ll dp[2][1000010];
int a[110];
int n;
int main()
{
	int x;
	cin>>n>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=x;j++)
		if(dp[0][j])
		{
			if(j+a[i]<=x)
				dp[0][j+a[i]]=(dp[0][j+a[i]]+dp[0][j])%1000000007ll;
			dp[1][j]=(dp[1][j]+dp[0][j])%1000000007ll;
		}
		for(int j=0;j<=x;j++)
		{
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
	}
	cout<<dp[0][x]<<endl;
	return 0;
}