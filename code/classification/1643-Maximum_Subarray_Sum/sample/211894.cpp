#include<bits/stdc++.h>
#define loop(i, a, b) for(lli i = a;i <= b; ++i)
#define rloop(i, a, b) for(lli i = a;i >= b; --i)
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lli long long int 
#define p (lli)(1e9 + 7)
using namespace std;
 
signed main(){
 
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
 
    fast;
    lli n;cin>>n;
    lli a[n];
    loop(i,0,n-1)
        cin>>a[i];
    lli dp[n];
    dp[0] = a[0];
    lli ans = dp[0];
    loop(i,1,n-1){
        dp[i] = max(dp[i-1]+a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
 
    return 0;
        
}