#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
int main()
{
	int n,x; cin>>n>>x;
   int a[n+1];
  for(int i=1;i<=n;i++)
    cin>>a[i];
  //int dp[x+1]={0};
  vector<ll> dp(x + 1, 0);
  dp[0]=1;
  for(int i=1;i<=x;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i-a[j]>=0)
        dp[i]=(dp[i]+dp[i-a[j]])%MOD;
    }
  }
  cout<<dp[x];
	return 0;
}
