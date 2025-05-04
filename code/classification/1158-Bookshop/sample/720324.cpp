#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e10+18
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=200005;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
#define ub upper_bound
#define  pq priority_queue
 int dp[1002][100002];
  int main(){
    //fastio;
   int i,x,j,n;
   cin>>n>>x;
    int a[n+1],b[n+1];
    for(i=1;i<=n;i++){
      cin>>a[i];
 
    }
     for(i=1;i<=n;i++){
      cin>>b[i];
    }
     for(i=1;i<=n;i++)
     {
      for(int j=1;j<=x;j++)
      {
        dp[i][j]=dp[i-1][j];
        if(j>=a[i])
          dp[i][j]=max(dp[i][j],b[i]+dp[i-1][j-a[i]]);
      }
 
     }
    cout<<dp[n][x];
   
  }
 