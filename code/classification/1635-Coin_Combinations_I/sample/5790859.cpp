// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define lld long double
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define pii pair<int,int>
#define loop(n) for(int i=0;i<n;i++)
#define fo(i,s,e) for(int i=s;i<e;i++)
#define test int _TT; cin>>_TT; for(int tt=1;tt<=_TT;tt++)
#define endl "\n"
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define all(a) a.begin(),a.end()
#define gsum(a) accumulate(a.begin(),a.end(),0LL)
#define gmax(a) *max_element(a.begin(),a.end())
#define gmin(a) *min_element(a.begin(),a.end())
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int mod = 1000000007;
//const int mod = 998244353;
const int inf = 2e9;
const lld pi = 3.1415926535897932;
const long long INF = 1e18;
 
 
int32_t main()    
{
 
   fastIO;
   //dp[i]=number of ways to produce i
   //dp[i]=for j (1 to n) dp[i-v[j]]
   //dp[0]=1
   
   int n,x;
   cin>>n>>x;
   vi v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   
   vi dp(x+1,0);
   dp[0]=1;
   for(int i=1;i<=x;i++){
   	  for(int j=0;j<n;j++){
   	  	if(i>=v[j]) dp[i]=(dp[i]+dp[i-v[j]])%mod;
   	  }
   }
   cout<<dp[x];
 
}