#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(int i=0;i<n;i++)
 
const int M = 1e9+7;
 
const int N = 1e6+10;
vector<int>  dp(N,0);
 
void solve()
{
 int n,x;
 cin >> n >> x;
    
 int a[n];
 f(i,n) cin >> a[i];
    
 dp[0] = 1;   
    
 f(i,x) f(j,n) if(i+1-a[j] >= 0) dp[i+1]=(dp[i+1]+dp[i+1-a[j]])%M;; 
        
 cout << dp[x] ;  
}
 
signed main()
{
 fast;   
 int t=1;
 while(t--) solve();
}
