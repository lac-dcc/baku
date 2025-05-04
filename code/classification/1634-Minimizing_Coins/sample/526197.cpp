#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 92233720ll;
const int nax = 101;
const int cax = 1e6+1;
int dp[cax],coins[nax];
int n,x;
void solve()
 { 
   cin>>n>>x;
  for(int i=1; i<=x; i++)
    dp[i]=inf;
   for(int i=1; i<=n; i++)
   {
     cin>>coins[i];
     dp[coins[i]] = 1;
   }
   dp[0] = 0;
   for(int i=1; i<=x; i++){
    for(int j=1; j<=n; j++){
      if(i>=coins[j])
         dp[i] = min(dp[i-coins[j]]+dp[coins[j]],dp[i]);
    }
   }
   if(dp[x] == inf)
       dp[x] = -1;
    cout<<dp[x];
 }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  /*#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   freopen("error.txt","w",stderr);
  #endif*/
  /* int t;
   cin>>t;
   while(t--)*/
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 
