#include <bits/stdc++.h>
using namespace std;
#define fast                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define mod 1000000007
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define int_max INT_MAX
#define int_min INT_MIN
#define ll_max 1e17
#define ll_min -1e17
 
int main()
{
	fast;
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
   
   int n,m,i,j,mn;
   string f,s;
   cin>>f>>s;
   n=f.length(), m = s.length();
 
   vector<vector<int>> dp(n+1,vector<int>(m+1));
   for(i=0;i<=n;i++)
   {
       for(j=0;j<=m;j++)
       {
           if(i*j==0)
             dp[i][j]= i+j;
           else if(f[i-1]==s[j-1])
              dp[i][j]=dp[i-1][j-1];
           else
           {
               mn = min(dp[i-1][j], dp[i][j-1]);
               mn = min(mn,dp[i-1][j-1]);
               dp[i][j]= mn +1;
           }
           
 
       }
   }
   cout<<dp[n][m];
   	
return 0;
}
