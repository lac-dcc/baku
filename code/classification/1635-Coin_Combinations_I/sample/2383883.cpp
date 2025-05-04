#include <bits/stdc++.h>
 
#define   ll         long long
#define   ull        unsigned long long
#define   lscn(x)    scanf("%lld",&x)
#define   lpri(x)    printf("%lld",&x)
#define   rep(i,x,n) for(i=x;i<n;i++)
#define   rev(i,n)   for(i=n-1;i>=0;i--)
#define   VC         vector<ll>
#define   MP         map<ll,ll>
#define   pb         push_back
#define   mp         make_pair
#define   gcd        __gcd
#define   tc(t)      cin>>t;while(t--)
#define   endl       "\n"
#define   lb         lower_bound
#define   ub         upper_bound
#define   ab(a)      a.begin(),a.end()
#define   fast       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   srt(v)     sort(v.begin(),v.end())
#define   inp(a,n)   rep(i,0,n)cin>>a[i]
#define mod 1000000007
using namespace std;
 
 
 int main()
 {
     ll n,x,i,j;
     cin>>n>>x;
     ll a[n+1];
     rep(i,1,n+1)
     cin>>a[i];
     ll dp[x+1];
     memset(dp,0,sizeof dp);
     dp[0]=1;
     rep(i,0,x+1)
     {
         rep(j,1,n+1)
         {
             if(i-a[j]>=0)
             dp[i]+=(dp[i-a[j]])%mod;
             dp[i]%=mod;
         }
     }
     cout<<dp[x]<<endl;
 }
 