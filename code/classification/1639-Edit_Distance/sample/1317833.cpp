#include<bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define popb  pop_back
#define popf  pop_front
#define sv(v) sort(v.begin(),v.end())
#define rsv(v) sort(v.rbegin(),v.rend())
#define mem(a,b) memset(a,b,sizeof(a))
#define M_PI 3.14159265358979323846
//#define mp make_pair
//#define bs binary_search
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 20
#endif
ll md=1000000007;
 
ll bexp(ll a,ll b)
{
  if(b==0)
  return 1;
  if(b==1)
  return a;
  ll r=bexp(a,b/2);
  r=r*r;
  if(b%2==0)
  return r;
  else
  return r*a;
}
 
ll solve(string s, string t)
{
  ll n,m,i,j;
  n=s.length();
  m=t.length();
  ll dp[n+1][m+1];
  memset(dp,0,sizeof(dp));
  for(i=1;i<=n;i++)
  {
    dp[i][0]=i;
  }
  for(i=1;i<=m;i++)
  {
    dp[0][i]=i;
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(s[i-1]==t[j-1])
      {
        dp[i][j]=dp[i-1][j-1];
      }
      else
      {
        dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) +1 ;
      }
    }
  }
 
  return dp[n][m];
}
int main()
{
   IOS;
   int test_case=1;
   //cin>>test_case;
   while(test_case--)
   {
      ll n,i,j,m,ans=0,k;
      string s,t;
      cin>>s>>t;
      ans=solve(s,t);
      cout<<ans;
   }
 
   return 0;
}