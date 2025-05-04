# include <bits/stdc++.h>
using namespace std;
 
# define ll long long int
 
const int mod = 1e9+7;
 
ll mod_add(ll a, ll b) {
    return ((a%mod) + (b%mod))%mod;
}
 
ll distinctWays(vector<int>& coins, vector<vector<ll>>& dp, int n, int x, int idx) {
    if (x < 0 || idx == n) return 0;
 
    if (dp[x][idx] != -1) return dp[x][idx];
 
    ll pickThis = distinctWays(coins,dp,n,x-coins[idx],idx);
    ll pickNext = distinctWays(coins,dp,n,x,idx+1);
 
    ll cntWays = pickThis + pickNext;
    dp[x][idx] = cntWays;
    return dp[x][idx];
}
 
int main() {
    int n,x;
    cin >> n >> x;
 
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
 
    // State: dp[i][j] = Distinct ways to reach sum [x-i] starting from index j
    // vector<vector<ll>> dp(x+1, vector<ll>(n, -1));
    // for (int i = 0; i < n; i++) dp[0][i] = 1;
 
    // for (int sum = 1; sum <= x; sum++) {
    //     for (int idx = n-1; idx >= 0; idx--) {
    //         ll pickThis = 0, pickNext = 0;
    //         if (sum >= coins[idx]) pickThis = dp[sum-coins[idx]][idx];
    //         if (idx < n-1) pickNext = dp[sum][idx+1];
    //         dp[sum][idx] = mod_add(pickThis,pickNext);
    //     }
    // }
    // ll res = dp[x][0];
    // cout << res << endl;
 
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j >= coins[i]) {
                dp[j] = mod_add(dp[j],dp[j-coins[i]]);
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}