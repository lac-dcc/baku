#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
const int MOD = 1e9+7, MX = 1e6+2;
int dp[MX];
 
signed main(){
    FIO int n, x; cin>>n>>x;
    int coin[n]; 
    for(int i=0; i<n; ++i){
        cin>>coin[i];
    }
    dp[0] = 1;
 
    for(int i=1; i<=x; ++i){
        for(int j=0; j<n; ++j){
            if(i - coin[j] < 0) continue;
            dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
        }
    }
    cout<<dp[x];
}