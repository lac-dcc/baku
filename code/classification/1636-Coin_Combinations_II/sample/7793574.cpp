#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
 
signed main() {
    int n, x, mod = 1e9+7;
    cin>>n>>x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    vector<int> dp(x+1, 0);
    dp[0] = 1;
 
    for (auto weight: a){
        for (int i = 1; i <= x; i++){
            if(i-weight>=0) dp[i] = (dp[i]+dp[i-weight])%mod;
        }
    }
    cout<<dp[x];
}
