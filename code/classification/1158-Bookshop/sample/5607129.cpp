// Code By :: HARSH BOGHARA
#define H_A_BOGHARA ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define lli long long int
#ifndef ONLINE_JUDGE
#include </Users/harsh/Downloads/Others/debug.txt>
#define dg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#include <bits/stdc++.h>
#define dg(x...)
#endif
 
using namespace::std;
void solve()
{
    int n,x,i,j;
    cin>>n>>x;
 
    int a[n],b[n];
    for (i=0; i<n; i++) {
        cin>>a[i];
    }
    for (i=0; i<n; i++) {
        cin>>b[i];
    }
 
    int dp[n+1][x+1];
 
    for (i=0; i<=n; i++) {
        for (j=0; j<=x; j++) {
            if (i==0 || j==0) {
                dp[i][j]=0;
            } else if (a[i-1]<=j) {
                dp[i][j]=max(dp[i-1][j],b[i-1]+dp[i-1][j-a[i-1]]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
 
    cout<<dp[n][x]<<"\n";
 
}
 
int main()
{
    H_A_BOGHARA
    solve();
    return 0;
}