#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
 
ll fun(ll target, vector<ll> &coins, ll n, vector<ll> &dp)
{
 
    // if(dp[n] != -1)
    // return dp[n];
 
    if(target == 0)
    return 0;
 
    // if(target < 0)
    // return 1e9;
 
    if(dp[target] != -1)
    return dp[target];
 
    ll count = 0,ans = 1e9;
    for(int j = 0; j < n; j++)
    {
        if(target - coins[j] >= 0)
        {
            count = 1 + fun(target - coins[j], coins, n, dp);
            ans = min(ans, count);
        }
    }
 
    return dp[target] = ans;
}
int main()
{
    ll n, target; 
    cin >> n >> target;
 
    vector<ll> coins(n);
    for(auto &it : coins) cin >> it;
 
    vector<ll> dp(target+1,-1);
    dp[0] = 0;
 
    ll ans = fun(target, coins, n,dp);
    if(dp[target] == 1e9)
    cout << -1 << endl;
    else
    cout << ans << endl;
 
    return 0;
}