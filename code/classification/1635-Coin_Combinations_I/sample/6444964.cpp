#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n,x,dp[1000001],num[101];
const int mod = 1e9+7;
 
signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>x>>n;
    for(int i = 1; i<=x; ++i) cin>>num[i];
    dp[0] = 1;
    for(int i = 0; i<=n; ++i){
        for(int j = 1; j<=x; ++j){
            if(i-num[j]>=0){
                dp[i]+=dp[i-num[j]];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[n];
}
